/* Ov000_ReleaseLogoResources -- release the logo scene resources, ov000. Releases the base
 * resource (heap[1]) and, when present, the region resource (heap[2]) via ZeroHalfThenFree. */

#include "game/engine.h"

extern void *NNSi_FndGetCurrentRootHeap(void);
void Ov000_ReleaseLogoResources(void) {
    int *h = (int *)NNSi_FndGetCurrentRootHeap();
    ZeroHalfThenFree((void *)h[1]);
    if (h[2] != 0) {
        ZeroHalfThenFree((void *)h[2]);
    }
}
