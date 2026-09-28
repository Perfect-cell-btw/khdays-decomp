#include "game/ov008_camp_menu.h"
/* When the global is mid key-sharing (word at +0x4e8 nonzero), set the low flag
 * bit at +0x4ad and store param_1 at +0x4ae; always flag the ready word at +0x4f4.
 * The global pointer is reloaded after each store (no strict aliasing). */
#define MISSION_CONTEXT ((int)data_ov008_02090f24.pContext)

void Ov008_Link_RequestLeave(int param_1) {
    int g = (int)data_ov008_02090f24.pContext;
    if (*(int *)(g + 0x4e8) != 0) {
        *(unsigned char *)(g + 0x4ad) = (*(unsigned char *)(g + 0x4ad) & ~1) | 1;
        *(unsigned char *)((int)data_ov008_02090f24.pContext + 0x4ae) = param_1;
    }
    *(int *)((int)data_ov008_02090f24.pContext + 0x4f4) = 1;
}
