/* AI step: measures the target, posts pose 1, sets up the wander heading and a random timer and
 * continues with the wander tick. */

extern void Ov298_AcquireTargetGapAndAngle(void *node);
extern void Ov107_PostTagUpdate(int obj, int arg1, int arg2);
extern int Rand16NextScaled(void);
extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov298_WanderTick(void);

void Ov298_Pose1SetupWithTimerThenAdvance(int node) {
    int *state = *(int **)(node + 4);

    Ov298_AcquireTargetGapAndAngle((void *)node);
    Ov107_PostTagUpdate(*state, 1, 0);
    state[0x14] = 0x900;
    state[0x23] = 0;
    state[0xc] = state[0xc] + state[0xa];
    state[0xd] = state[0xc];
    state[0x15] = 0x1fe0;
    state[0x17] = Rand16NextScaled() + 0xff0;
    SetIndexedSlot((void *)node, *(signed char *)(node + 0x20), Ov298_WanderTick);
}
