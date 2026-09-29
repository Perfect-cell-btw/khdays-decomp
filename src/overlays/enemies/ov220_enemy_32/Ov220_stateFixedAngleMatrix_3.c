/* AI step: rotates the guard offset by the heading and, when the animation ends, posts pose 0xb and
 * continues with the guard tick. */

#include "game/enemy_common.h"

extern void MTX_RotY33_();
extern void MTX_MultVec33();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern short data_0203d210[];
extern void Ov220_GuardTick(void);
void Ov220_stateFixedAngleMatrix_3(int *node) {
    int *state = (int *)node[1];
    int mtx[9];
    int angle = (int)(((unsigned)(((long long)(int)(unsigned)state[3] * 0x28be60db9391LL +
                       0x80000000000LL) >> 0x20) << 4) >> 0x10) >> 4;
    MTX_RotY33_(mtx, (int)data_0203d210[angle * 2], (int)data_0203d210[angle * 2 + 1]);
    MTX_MultVec33(*(int *)(*state + 0x394) + 0x2c, mtx, state + 9);
    if (*(unsigned char *)(state[1] + 0xad) == 0) {
        Ov107_PostTagUpdate((Actor *)(*state), 0xb, 1);
        state[5] = 0;
        *(signed char *)((char *)state + 0x3e) = 0;
        SetIndexedSlot(node, *(signed char *)(node + 8), Ov220_GuardTick);
    }
}
