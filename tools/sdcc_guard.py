#!/usr/bin/env python3
"""Serialize SDCC invocations and bound their address space and elapsed time.

The lock is shared by exported Vexel projects for this user. The limit is
inherited by SDCC's children; it is a host build constraint, not an MSX budget.
A kernel CPU limit remains effective if an outer build forcibly kills this guard.
Queue waiting is recorded separately from time spent running the compiler.
"""
import argparse
import fcntl
import json
import os
from pathlib import Path
import resource
import signal
import subprocess
import sys
import tempfile
import time


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--memory-mb', type=int, default=2048)
    parser.add_argument('--timeout', type=int, default=180)
    parser.add_argument('--log', type=Path)
    parser.add_argument('command', nargs=argparse.REMAINDER)
    args = parser.parse_args()
    if not args.command or args.memory_mb < 32 or args.timeout < 1:
        parser.error('a command, at least 32 MiB and a positive timeout are required')
    limit = args.memory_mb * 1024 * 1024
    inherited_cpu_hard = resource.getrlimit(resource.RLIMIT_CPU)[1]
    cpu_hard = args.timeout+1
    if inherited_cpu_hard != resource.RLIM_INFINITY:
        cpu_hard = min(cpu_hard, inherited_cpu_hard)
    cpu_soft = min(args.timeout, cpu_hard)

    def cancelled(signum, frame):
        raise KeyboardInterrupt

    signal.signal(signal.SIGTERM, cancelled)

    def constrain():
        hard = resource.getrlimit(resource.RLIMIT_AS)[1]
        available = min(limit, hard) if hard != resource.RLIM_INFINITY else limit
        resource.setrlimit(resource.RLIMIT_AS, (available, available))
        resource.setrlimit(resource.RLIMIT_CORE, (0, 0))
        # The wall-clock supervisor normally acts first. This inherited kernel
        # backstop also bounds computation if a whole-build controller dies.
        resource.setrlimit(resource.RLIMIT_CPU, (cpu_soft, cpu_hard))

    lock = Path(tempfile.gettempdir()) / f'vexel-sdcc-{os.getuid()}.lock'
    queued = time.monotonic()
    with lock.open('a') as gate:
        fcntl.flock(gate, fcntl.LOCK_EX)
        started = time.monotonic()
        child = subprocess.Popen(args.command, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                                 text=True, start_new_session=True, preexec_fn=constrain,
                                 # Keep the shared lock alive even if this
                                 # supervisor is forcibly killed by its owner.
                                 pass_fds=(gate.fileno(),))
        reason = 'completed'
        try:
            stdout, stderr = child.communicate(timeout=args.timeout)
        except subprocess.TimeoutExpired:
            reason = 'timeout'
            os.killpg(child.pid, signal.SIGKILL)
            stdout, stderr = child.communicate()
        except BaseException:
            os.killpg(child.pid, signal.SIGKILL)
            child.wait()
            raise
        usage = resource.getrusage(resource.RUSAGE_CHILDREN)
        cpu_seconds = usage.ru_utime+usage.ru_stime
        if child.returncode and reason == 'completed':
            reason = 'compiler-failure'
            if child.returncode == -signal.SIGXCPU or (child.returncode == -signal.SIGKILL and cpu_seconds >= cpu_soft):
                reason = 'cpu-limit'
            if any(s in (stdout+stderr).lower() for s in ('out of memory', 'no more memory', 'cannot allocate memory',
                                                        'memory allocation', 'malloc failed', 'memoryerror')):
                reason = 'memory-limit'
        row = {'command': args.command, 'memory_limit_mb': args.memory_mb,
               'timeout_seconds': args.timeout, 'seconds': round(time.monotonic()-started, 3),
               'queue_seconds': round(started-queued, 3),
               'cpu_limit_seconds': cpu_soft, 'cpu_seconds': round(cpu_seconds, 3),
               'peak_rss_kb': usage.ru_maxrss,
               'returncode': child.returncode, 'reason': reason}
        sys.stdout.write(stdout); sys.stderr.write(stderr)
        if args.log:
            args.log.parent.mkdir(parents=True, exist_ok=True)
            with args.log.open('a') as log:
                log.write(json.dumps(row)+'\n')
        if child.returncode:
            print(f'SDCC guard: {reason}; peak RSS {row["peak_rss_kb"]//1024} MiB, '
                  f'address-space cap {args.memory_mb} MiB, elapsed {row["seconds"]} s', file=sys.stderr)
        if reason in ('timeout', 'cpu-limit', 'memory-limit'):
            return 125
        return child.returncode if child.returncode >= 0 else 128-child.returncode


if __name__ == '__main__':
    raise SystemExit(main())
