#if EDW_VEXEL
/* Pure service rules occupy a separate page-B module. Their page-C caller
 * copies all results before replacing this bank with popup/infobar code. */
#include "vx_services.inc"
#endif
