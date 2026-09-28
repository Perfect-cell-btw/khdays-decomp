/* AI step: advances the timer by the owner's frame step until it passes 0x6ee; then acquires the
 * nearest target and faces it, clears flags 0x82 in the high byte of the actor's flags, posts pose
 * 0 and installs the next step. */

struct hw60 { unsigned short lo : 8, hi : 8; };
extern int Ov107_FindNearestObject(void *obj, int flag);
extern void VEC_Subtract(void *a, void *b, void *out);
extern int func_020050b4(int x, int z);
extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov194_AiStep_RollDelayQueueAction2OnAnimEnd(void);

void Ov194_stTickAimTimerC(int *node) {
    int a = node[0];
    int *state = (int *)node[1];
    int buf[3];
    int v = state[0xc] + *(int *)(a + 0x2c);
    state[0xc] = v;
    if (v < 0x6ee) return;
    {
        int r = Ov107_FindNearestObject(*state, 0);
        state[2] = r;
        if (r != 0) {
            int ang;
            VEC_Subtract((void *)(r + 0x74), (void *)state[0x10], buf);
            ang = func_020050b4(buf[0], buf[2]);
            state[4] = ang;
            state[3] = ang;
        }
    }
    ((struct hw60 *)(*state + 0x60))->hi &= ~0x82;
    Ov107_PostTagUpdate(*state, 0, 0);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov194_AiStep_RollDelayQueueAction2OnAnimEnd);
}
