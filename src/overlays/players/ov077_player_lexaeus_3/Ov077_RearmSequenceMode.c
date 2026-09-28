/* Re-arms the five sequence slots of a block for the given mode: sets the
 * block's own mode word, then for each slot releases whatever handle it still
 * holds, retimes it against the block's period and restarts it from zero. The
 * actor is not touched -- the caller passes it only because every routine in
 * the family takes it first. */

#include "nitro/types.h"

extern void NNS_G3dRenderObjRemoveAnmObj(void *p, int handle);
extern void BindAnimTrack(void *p, u16 idx, int a, short b);
extern void Anim_SetFrameWrapped(void *p, u16 idx, int a);

void Ov077_RearmSequenceMode(int self, int *block, int mode)
{
    int i;

    switch (mode) {
    case 0:
        block[0] = 1;
        break;
    case 1:
        block[0] = 3;
        break;
    case 2:
        block[0] = 2;
        break;
    case 3:
        block[0] = 3;
        break;
    }
    for (i = 0; i < 5; i++) {
        if (block[i + 4] != 0) {
            NNS_G3dRenderObjRemoveAnmObj((char *)block + 0x24, block[i + 4]);
            block[i + 4] = 0;
        }
        BindAnimTrack((char *)block + 4, (u16)i,
                      *(int *)((char *)block + 0x10c), (short)mode);
        Anim_SetFrameWrapped((char *)block + 4, (u16)i, 0);
    }
}
