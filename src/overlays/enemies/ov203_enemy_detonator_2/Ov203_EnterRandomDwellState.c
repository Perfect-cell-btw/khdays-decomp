/* Init state: clears the current and pending actions, clears bit 0 of the model's flag byte,
 * records pointers to the actor's velocity, position and model busy flag, sets the initial flag
 * bits, picks a random dwell time and installs the first action, the dispatcher and the motion
 * step. */

#include "game/engine.h"

extern void SetIndexedSlot(int, int, void *);
extern void Ov203_stateSetFlagsClearBit(void);
extern void Ov203_DispatchSubStateByte(void);
extern void Ov203_MotionTick(void);

struct flagword { unsigned f8 : 8; };

void Ov203_EnterRandomDwellState(int param_1) {
    int *obj = *(int **)(param_1 + 4);
    unsigned short h;
    int lo, range;

    *(char *)(*obj + 0x1c6) = 0;
    *(char *)(*obj + 0x1c7) = -1;
    ((struct flagword *)(*(int *)(*obj + 0x38c) + 8))->f8 &= ~1;
    obj[0xf] = *obj + 0xb0;
    obj[0x10] = *obj + 0x74;
    obj[0x11] = *(int *)(*obj + 900) + 0xad;
    h = *(unsigned short *)(*obj + 0x60);
    *(unsigned short *)(*obj + 0x60) =
        h & ~0xff00 | (((((unsigned int)h << 0x10) >> 0x18 | 6) << 0x18) >> 0x10);
    lo = *(int *)(*obj + 0x224);
    range = *(int *)(*obj + 0x228) - lo;
    if (range < 0) {
        range = -range;
    }
    obj[0xc] = lo + RandNextScaled(range + 1);
    SetIndexedSlot(param_1, 1, Ov203_stateSetFlagsClearBit);
    SetIndexedSlot(param_1, 0, Ov203_DispatchSubStateByte);
    SetIndexedSlot(param_1, 2, Ov203_MotionTick);
}
