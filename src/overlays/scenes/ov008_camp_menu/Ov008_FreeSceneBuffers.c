#include "game/ov008_camp_menu.h"
/* Ov008_FreeSceneBuffers -- free the title scene's dynamic buffers, ov006.
 * Frees the primary buffer (base[0]) if allocated, then walks the 4-entry buffer table at
 * base+8 (8-byte stride), freeing and nulling each non-null pointer. */
extern void NNSi_FndFreeFromDefaultHeap(int p);
#define MISSION_CONTEXT ((int)data_ov008_02090f24.pContext)

void Ov008_FreeSceneBuffers(void) {
    unsigned int i;
    if (*(int *)MISSION_CONTEXT != 0) {
        NNSi_FndFreeFromDefaultHeap(*(int *)MISSION_CONTEXT);
        *(int *)MISSION_CONTEXT = 0;
    }
    i = 0;
    do {
        int p = *(int *)(MISSION_CONTEXT + i * 8 + 8);
        if (p != 0) {
            NNSi_FndFreeFromDefaultHeap(p);
            *(int *)(MISSION_CONTEXT + i * 8 + 8) = 0;
        }
        i = i + 1 & 0xff;
    } while (i < 4);
}
