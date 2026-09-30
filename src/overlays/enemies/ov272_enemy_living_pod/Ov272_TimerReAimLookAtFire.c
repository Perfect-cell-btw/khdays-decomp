/* AI state step: advances the timer by the owner's frame step and waits until it passes 0x6ee; then
 * turns toward the nearest object (look-at matrix to quaternion), clears flags 0x82 in the high
 * byte of the actor's flags, posts a tag update and installs the next step. */

#include "game/enemy_common.h"

struct hw60 { unsigned short lo : 8, hi : 8; };
struct blk16 { int a, b, c, d; };
extern int Ov107_FindNearestObject(int a, int b);
extern void Mtx33_LookAt(int *out, int *m, int *a, int *b);
extern void Quat_FromMtx33(int *dst, int *m);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern int data_02042264[];
extern void Ov272_AiStep_QueueAction2OnAnimEnd(void);
void Ov272_TimerReAimLookAtFire(int *node) {
    int buf[9];
    int *obj = (int *)node[0];
    int *state = (int *)node[1];
    int t = state[0x14] + obj[0xb];
    state[0x14] = t;
    if (t < 0x6ee) return;
    state[2] = Ov107_FindNearestObject(*state, 0);
    if (state[2] != 0) {
        int *sub = (int *)state[0x13];
        Mtx33_LookAt(buf, (int *)(state[2] + 0x74), sub, data_02042264);
        Quat_FromMtx33(state + 7, buf);
        *(struct blk16 *)(state + 3) = *(struct blk16 *)(state + 7);
    }
    ((struct hw60 *)(*state + 0x60))->hi &= ~0x80;
    Ov107_PostTagUpdate((Actor *)(*state), 0, 0);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov272_AiStep_QueueAction2OnAnimEnd);
}
