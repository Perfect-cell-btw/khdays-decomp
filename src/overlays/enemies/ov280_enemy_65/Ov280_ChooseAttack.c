/* Attack choice of the ov263 enemy (variant of ov231/ov232's): a d100 is drawn and the target
 * re-acquired (Ov280_AcquireTarget); by the +0x20 distance the owner requests sub-state 5/6/7 with
 * thresholds 10/60 (closer than 3.0), 5/6/8/7 at 40/85/95 (closer than 5.0) or 5/6/8 at 25/50
 * (farther). When a sub-state was requested the +0x24 delay is re-rolled in [+0x224, +0x228] and 1
 * is returned. */

#include "game/engine.h"

extern void Ov280_AcquireTarget(int *node);

static inline int RandRange(int low, int high)
{
    int span = high - low;
    if (span < 0) span = -span;
    return low + RandNextScaled(span + 1);
}

int Ov280_ChooseAttack(int *node)
{
    int *state = (int *)node[1];
    unsigned short roll = RandNextScaled(100);

    Ov280_AcquireTarget(node);
    if (state[8] < 0x3000) {
        *(unsigned char *)(*state + 0x1c7) = roll < 0xa ? 5 : (roll < 0x3c ? 6 : 7);
    } else if (state[8] < 0x5000) {
        *(unsigned char *)(*state + 0x1c7) = roll < 0x28 ? 5 : (roll < 0x55 ? 6 : (roll < 0x5f ? 8 : 7));
    } else {
        *(unsigned char *)(*state + 0x1c7) = roll < 0x19 ? 5 : (roll < 0x32 ? 6 : 8);
    }
    if (*(signed char *)(*state + 0x100 + 0xc7) != -1) {
        state[9] = RandRange(*(int *)(*state + 0x224), *(int *)(*state + 0x228));
        return 1;
    }
    return 0;
}
