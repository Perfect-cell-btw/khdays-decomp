#include "game/engine.h"

extern void ClearGlobalArrayInt(int id);
extern void NNSi_FndFreeFromDefaultHeap(void *p);
extern char **data_0204be08;

/* Shuts the 3D subsystem down: blanks the three engines, stops the two effects (the second only
 * when it is not already gated) and frees the four buffers. */
void Shutdown3DSubsystem(void) {
    char *ctx = (char *)((void **)&data_0204be08)[1];
    setDualArrayEntry(0, 0, 0);
    setDualArrayEntry(1, 0, 0);
    setDualArrayEntry(2, 0, 0);
    ClearGlobalArrayInt(0x11);
    if ((LoadGlobalU16At0() & 2) == 0) {
        ClearGlobalArrayInt(0x12);
    }
    NNSi_FndFreeFromDefaultHeap(*(void **)(ctx + 0x9c));
    NNSi_FndFreeFromDefaultHeap(*(void **)(ctx + 0x10));
    NNSi_FndFreeFromDefaultHeap(*(void **)(ctx + 0x14));
    NNSi_FndFreeFromDefaultHeap(*(void **)(ctx + 0xc));
}
