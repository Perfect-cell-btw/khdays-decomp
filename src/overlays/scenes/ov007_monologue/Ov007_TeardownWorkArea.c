#include "game/engine.h"

extern int NNSi_FndGetCurrentRootHeap(void);
extern void Ov007_FreeResourceRecordBuffer(void *p);
extern void NNSi_FndFreeFromDefaultHeap(void *p);
extern int data_ov007_0204d3c0;
extern int data_ov007_0204d420;

/* Tear down the ov007 root work area: release its sub-objects and buffers, free
 * the two heap allocations, and reset the two module globals (-1 / 0). */
void Ov007_TeardownWorkArea(void) {
    int root = NNSi_FndGetCurrentRootHeap();

    Ov007_FreeResourceRecordBuffer((void *)(root + 8));
    TileTextRenderer_Destroy((void *)(root + 0x30));
    FontResource_Destroy((void *)(root + 0x24));
    Obj_Release((void *)(root + 0x107c));
    NNSi_FndFreeFromDefaultHeap(*(void **)(root + 4));
    ZeroHalfThenFree(*(void **)root);
    data_ov007_0204d3c0 = -1;
    data_ov007_0204d420 = 0;
}
