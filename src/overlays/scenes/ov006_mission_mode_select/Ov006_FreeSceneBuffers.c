#include "game/ov006_mission_mode_select.h"
/* Ov006_FreeSceneBuffers -- free the Mission Mode scene's dynamic buffers, ov006.
 * Frees the primary buffer (base[0]) if allocated, then walks the 4-entry buffer table at
 * base+8 (8-byte stride), freeing and nulling each non-null pointer. */
extern void NNSi_FndFreeFromDefaultHeap(int p);
#define MISSION_CONTEXT (data_ov006_020565e4.pContext)

void Ov006_FreeSceneBuffers(void) {
    unsigned int i;
    if ((int)MISSION_CONTEXT->primaryBuffer != 0) {
        NNSi_FndFreeFromDefaultHeap((int)MISSION_CONTEXT->primaryBuffer);
        *(int *)data_ov006_020565e4.pContext = (void *)(0);
    }
    i = 0;
    do {
        int p = MISSION_CONTEXT->workBuffers[i].buffer;
        if (p != 0) {
            NNSi_FndFreeFromDefaultHeap(p);
            MISSION_CONTEXT->workBuffers[i].buffer = 0;
        }
        i = i + 1 & 0xff;
    } while (i < 4);
}
