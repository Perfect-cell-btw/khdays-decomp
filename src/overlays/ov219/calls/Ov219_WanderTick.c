/* Wander tick of the ov219 enemy (and its byte-identical twin): a negative distance to the target
 * ends the state; within 0x4800 the +0x14 clock resets, the tick hands off to the approach state
 * and runs it at once, and the actor wants animation 1; beyond it the idle countdown may end the
 * state, else animation 0 is wanted. A wanted animation different from the +0x44 one is played. */
extern int Ov219_DistanceToTarget(int *node);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov219_ApproachTick(int *node);
extern int Ov219_IdleCountdown(int *node, int value);
extern void Ov107_PostTagUpdate(int actor, int anim, int flag);

void Ov219_WanderTick(int *node)
{
    int *state = (int *)node[1];
    int dist;
    int anim;

    dist = Ov219_DistanceToTarget(node);
    if (dist < 0) {
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
        return;
    }
    if (dist < 0x4800) {
        state[5] = 0;
        anim = 1;
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov219_ApproachTick);
        Ov219_ApproachTick(node);
    } else {
        if (Ov219_IdleCountdown(node, dist) != 0) {
            SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
            return;
        }
        anim = 0;
    }
    if (anim < 0) {
        return;
    }
    if (state[0x11] != anim) {
        state[0x11] = anim;
        Ov107_PostTagUpdate(*state, anim, 1);
    }
}
