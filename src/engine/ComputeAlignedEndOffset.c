/* Returns the end offset of a slot's data (its base plus the size recorded for the slot), aligned
 * to the 32/64/128/256-byte boundary its flags select. */

#include "game/engine.h"

extern int IntArray_Get();
unsigned int ComputeAlignedEndOffset(int param_1, int *param_2)
{
    int a = DispObjList_GetEngine(param_1);
    unsigned int v;
    a = IntArray_Get((int)(param_2 + 0xd), a);
    v = *param_2 + a;
    switch (param_2[2] >> 0x14 & 3) {
    case 0: return (v + 0x1f) & 0xffffffe0;
    case 1: return (v + 0x3f) & 0xffffffc0;
    case 2: return (v + 0x7f) & 0xffffff80;
    case 3: return (v + 0xff) & 0xffffff00;
    }
    return v;
}
