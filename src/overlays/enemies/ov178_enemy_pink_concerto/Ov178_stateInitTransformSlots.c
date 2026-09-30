/* Init state: clears the current and pending actions, clears bit 0 of the model's flag byte, points
 * the state at the actor's position (+0x74), sets the initial flag bits, zeroes the rotation and
 * installs the dispatcher, the first action step and the timer step. */

#include "game/engine.h"

struct bf { unsigned b : 8; };
struct blk16 { int a, b, c, d; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov178_ov115_DispatchSubStateByte(void);
extern void Ov178_stDivStoreField(void);
extern void Ov178_stateSetFlagsClearBit(void);
void Ov178_stateInitTransformSlots(int *node) {
    int *state = (int *)node[1];
    *(signed char *)(*state + 0x1c6) = 0;
    *(signed char *)(*state + 0x1c7) = 0xff;
    ((struct bf *)(*(int *)(*state + 0x388) + 8))->b &= ~1;
    state[2] = *state + 0x74;
    state[3] = 0;
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 6) << 0x18) >> 0x10));
    }
    Obj_SetFourWords(state + 0x19, 0, 0, 0, 0);
    *(struct blk16 *)(state + 0x1d) = *(struct blk16 *)(state + 0x19);
    SetIndexedSlot(node, 0, Ov178_ov115_DispatchSubStateByte);
    SetIndexedSlot(node, 1, Ov178_stateSetFlagsClearBit);
    SetIndexedSlot(node, 2, Ov178_stDivStoreField);
}
