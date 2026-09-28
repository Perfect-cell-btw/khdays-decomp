#include "game/ov008_camp_menu.h"
/* Ov008_FreeSceneBuffers -- free the mission context's buffers: the packet buffer if allocated,
 * then each of the four work buffers, nulling what it frees. */
extern void NNSi_FndFreeFromDefaultHeap(void *p);
#define MISSION_CONTEXT (data_ov008_02090f24.pContext)

void Ov008_FreeSceneBuffers(void) {
    unsigned int i;
    if (MISSION_CONTEXT->primaryBuffer != 0) {
        NNSi_FndFreeFromDefaultHeap(MISSION_CONTEXT->primaryBuffer);
        MISSION_CONTEXT->primaryBuffer = 0;
    }
    i = 0;
    do {
        void *p = MISSION_CONTEXT->workBuffers[i].buffer;
        if (p != 0) {
            NNSi_FndFreeFromDefaultHeap(p);
            MISSION_CONTEXT->workBuffers[i].buffer = 0;
        }
        i = i + 1 & 0xff;
    } while (i < 4);
}
