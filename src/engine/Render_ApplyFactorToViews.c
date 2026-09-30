/* Scale-and-dispatch pass over the selected entity slots' two intrusive lists
 * (heads at gEntityMgr+idx*4+{0x84,0x64}, same table Render_DrawViewLists walks).
 * The +0x84 list scales each node's own factor at +0x180 by `scale` in 1.19.12
 * fixed point before dispatching; the +0x64 list passes `scale` through. */

#include "nitro/fx_types.h"
#include "game/engine.h"

extern int gEntityMgr;

void Render_ApplyFactorToViews(unsigned int mask, fx32 scale) {
    int i;
    unsigned int bit = 1;

    for (i = 0; i < *(int *)gEntityMgr; i++, bit <<= 1) {
        if (mask & bit) {
            unsigned short idx = (unsigned short)i;
            int *p;
            int slot = gEntityMgr + 4 + idx * 8;

            for (p = *(int **)(gEntityMgr + idx * 4 + 0x84); p != 0; p = *(int **)p) {
                DetachThenApplyNode(slot, (unsigned int *)(p + 3),
                              (fx32)(((fx64)scale * p[0x60] + 0x800) >> 12));
            }
            for (p = *(int **)(gEntityMgr + idx * 4 + 0x64); p != 0; p = *(int **)p) {
                DetachThenApplyNode(slot, (unsigned int *)(p + 3), scale);
            }
        }
    }
}
