/* Resets the action state, caches the position/anim pointers, rolls the move timer and installs the
 * AI slots. */

#include "game/engine.h"

extern void SetIndexedSlot(int, int, void *);
extern void Ov131_stateSetFlagsClearBit(void);
extern void Ov131_stDispatchByStateByte(void);
extern void Ov131_UpdateHeadingAndVelocity(void);

struct flagword { unsigned f8 : 8; };

void Ov131_AiStateInit(int param_1) {
    int *obj = *(int **)(param_1 + 4);
    unsigned short h;
    int lo, range;

    *(char *)(*obj + 0x1c6) = 0;
    *(char *)(*obj + 0x1c7) = -1;
    ((struct flagword *)(*(int *)(*obj + 0x388) + 8))->f8 &= ~1;
    obj[0x10] = *obj + 0xb0;
    obj[0x11] = *obj + 0x74;
    obj[0x12] = *(int *)(*obj + 900) + 0xad;
    h = *(unsigned short *)(*obj + 0x60);
    *(unsigned short *)(*obj + 0x60) =
        h & ~0xff00 | (((((unsigned int)h << 0x10) >> 0x18 | 6) << 0x18) >> 0x10);
    lo = *(int *)(*obj + 0x224);
    range = *(int *)(*obj + 0x228) - lo;
    if (range < 0) {
        range = -range;
    }
    obj[0xd] = lo + RandNextScaled(range + 1);
    SetIndexedSlot(param_1, 1, Ov131_stateSetFlagsClearBit);
    SetIndexedSlot(param_1, 0, Ov131_stDispatchByStateByte);
    SetIndexedSlot(param_1, 2, Ov131_UpdateHeadingAndVelocity);
}
