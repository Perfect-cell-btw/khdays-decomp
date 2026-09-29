#include "game/engine.h"

extern int *NNSi_FndGetCurrentRootHeap(void);
extern void NNSi_FndFreeFromDefaultHeap(int ptr);
extern void func_02003948(int result);

/* Tear down the ov010 root-heap work area: swap the active list slot out, and if
 * a buffer is allocated free its sub-objects and the buffer itself, then restore
 * the slot and signal completion (-2). */
void Ov010_TeardownWorkArea(void) {
    int *root = NNSi_FndGetCurrentRootHeap();
    int saved = Heap_GetCurrent();

    Heap_SetCurrent(0);
    if (*root != 0) {
        TileTextRenderer_Destroy(root + 6);
        FontResource_Destroy(root + 3);
        NNSi_FndFreeFromDefaultHeap(*root);
        *root = 0;
    }
    Heap_SetCurrent(saved);
    func_02003948(-2);
}
