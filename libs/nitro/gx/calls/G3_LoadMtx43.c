/* Geometry command 0x17 (MTX_LOAD_4x3) followed by the matrix's 48 bytes into the geometry FIFO. */
#include "nitro/fx.h"

extern void GX_SendFifo48B(const void *src, void *dst);

void G3_LoadMtx43(const MtxFx43 *m) {
    *(volatile unsigned int *)0x4000400 = 0x17;
    GX_SendFifo48B(m, (void *)0x4000400);
}
