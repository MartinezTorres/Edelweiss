#include <common.h>
#include <gameplay/password.h>
USING_MODULE(password, PAGE_C);
void wolfi_in_saloon(void) {
    trampoline_page_c(MODULE_SEGMENT(password, PAGE_C), quest_saloon);
}
