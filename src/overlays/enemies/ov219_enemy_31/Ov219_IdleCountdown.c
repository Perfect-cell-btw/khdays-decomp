/* Idle countdown of the ov219 enemy (and its byte-identical twin). The +0x1c timer loses the
 * frame-time; once it runs out it is re-rolled to +0x224 + rand(|+0x228 - +0x224| + 1), a caller
 * value above 0x4000 forces sub-state 5, and the call reports 1 when a sub-state is pending. */

#include "nitro/types.h"

extern int RandNextScaled(int bound);

int Ov219_IdleCountdown(int *node, int value)
{
    int *state = (int *)node[1];
    int lo;
    int d;

    state[7] -= *(int *)(*node + 0x2c);
    if (state[7] <= 0) {
        lo = *(int *)(*state + 0x224);
        d = *(int *)(*state + 0x228) - lo;
        state[7] = lo + RandNextScaled((d < 0 ? -d : d) + 1);
        if (value > 0x4000) {
            *(u8 *)(*state + 0x1c7) = 5;
        }
        if (*(signed char *)(*state + 0x1c7) != -1) {
            return 1;
        }
    }
    return 0;
}
