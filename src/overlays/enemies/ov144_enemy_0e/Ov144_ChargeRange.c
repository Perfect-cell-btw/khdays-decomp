/* Charge range of the ov144 enemy (and its byte-identical twin): 0x3000/0x5000/0xa000 for the
 * +0x3bc size class (-1 otherwise). With the flag set and the +0x38c item busy the range is
 * split by the item's animation progress (queryTableEntry/be68, frame 1 when +0x3f0 is clear):
 * the covered part when +0x3f0 is set, the remainder otherwise; an idle item yields the full
 * range only while +0x3f0 is set. */

#include "nitro/types.h"

extern int queryTableEntry(int item, int a);
extern int Obj_GetCellScaledField(int item, int a, int frame);
extern s64 func_020201b8(s64 num, s64 den);

int Ov144_ChargeRange(int *state, int flag)
{
    int item;
    int range;
    int total;
    int cur;
    s64 q;

    switch (*(int *)(*state + 0x3bc)) {
    case 0:
        range = 0x3000;
        break;
    case 1:
        range = 0x5000;
        break;
    case 2:
        range = 0xa000;
        break;
    default:
        return -1;
    }
    item = *(int *)(*state + 0x38c);
    if (flag == 0) {
        return range;
    }
    if (*(u8 *)(item + 0xad) == 0) {
        if (*(int *)(*state + 0x3f0) == 0) {
            range = 0;
        }
        return range;
    }
    total = queryTableEntry(item, 0);
    cur = Obj_GetCellScaledField(item, 0, (short)(*(int *)(*state + 0x3f0) == 0 ? 1 : 0));
    if (cur <= 0) {
        return 0;
    }
    q = func_020201b8((s64)range * total, cur);
    if (*(int *)(*state + 0x3f0) != 0) {
        return (int)q;
    }
    return (int)(range - q);
}
