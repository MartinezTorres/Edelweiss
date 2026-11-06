#ifndef EDW_PASSWORD_H
#define EDW_PASSWORD_H
#include <stdint.h>
/* Enter the password page-C module before calling. The buffer belongs to
 * the engine; only its ten byte values cross the Vexel boundary. */
void password_encode(char destination[11]);
uint8_t password_restore(const char *code, uint8_t length);
void quest_saloon(void);
#endif
