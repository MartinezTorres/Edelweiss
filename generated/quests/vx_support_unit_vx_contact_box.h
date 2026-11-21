#include "vexel.h"
#undef VX_VALUE_LOCATION
#define VX_VALUE_LOCATION VX_RESIDENT
#include "vx_support_value_base.h"
#include "vx_support_value_add8.h"
#include "vx_support_value_lt8.h"
#undef VX_VALUE_LOCATION
#define VX_VALUE_LOCATION
