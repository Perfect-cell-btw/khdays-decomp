/* Geometry command 0x1a (MTX_MULT_3x3) followed by the matrix's 36 bytes into the geometry FIFO. */
#include "nitro/fx.h"

extern void MI_Copy36B(const void *src, void *dst);

void G3_MultMtx33(const MtxFx33 *m) {
    *(volatile unsigned int *)0x4000400 = 0x1a;
    MI_Copy36B(m, (void *)0x4000400);
}
