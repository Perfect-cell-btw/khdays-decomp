/* Starts the ov032 enemy's effect block (and its byte-identical twins) unless it is already
 * running outside states 4/5: releases the five handles it still holds, retimes sequences 0, 2
 * and 1 against the owner's +0x22f8 period from zero, resets the three +0xbc scales to 1.0 and
 * enters state 1. */

#include "nitro/types.h"

extern void NNS_G3dRenderObjRemoveAnmObj(void *p, int handle);
extern int Ov022_GetWordAt0x348Plus4(void *p);
extern void BindAnimTrack(void *p, u16 idx, int a, short b);

void Ov072_EffectBlockStart(int self, int *block)
{
    int i;

    if (*(u8 *)((char *)block + 0x114) != 0 && (u8)(*(u8 *)((char *)block + 0x114) + 0xfc) > 1) {
        return;
    }
    for (i = 0; i < 5; i++) {
        if (block[i + 6] != 0) {
            NNS_G3dRenderObjRemoveAnmObj((char *)block + 0x2c, block[i + 6]);
            block[i + 6] = 0;
        }
    }
    BindAnimTrack((char *)block + 0xc, 0, Ov022_GetWordAt0x348Plus4((void *)(self + 0x22f8)), 0);
    BindAnimTrack((char *)block + 0xc, 2, Ov022_GetWordAt0x348Plus4((void *)(self + 0x22f8)), 0);
    BindAnimTrack((char *)block + 0xc, 1, Ov022_GetWordAt0x348Plus4((void *)(self + 0x22f8)), 0);
    block[0x31] = 0x1000;
    block[0x30] = 0x1000;
    block[0x2f] = 0x1000;
    *(u8 *)((char *)block + 0x114) = 1;
}
