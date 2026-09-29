/* Initialises the context entry of the current root heap owner; returns 0. */

#include "game/engine.h"

extern int *NNSi_FndGetCurrentRootHeap(void);

int ContextEntry_InitForRootHeap(void) {
    InitContextEntryOnce(*NNSi_FndGetCurrentRootHeap());
    return 0;
}
