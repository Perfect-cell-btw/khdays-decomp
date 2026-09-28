/* AI step: advances the timer by the owner's frame step until it passes 0x6ee; then acquires a
 * target and faces it, clears flags 0x82 in the high byte of the actor's flags, posts pose 0 and
 * installs the random-delay step. */

struct hw60 { unsigned short lo : 8, hi : 8; };
extern int Ov193_FindTarget(void *obj, int flag);
extern void VEC_Subtract(void *a, void *b, void *out);
extern int func_020050b4(int x, int z);
extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov193_stRandDelayInRange(void);

void Ov193_stTickAimTimerB(int *node) {
    int a = node[0];
    int *state = (int *)node[1];
    int buf[3];
    int v = state[0xb] + *(int *)(a + 0x2c);
    state[0xb] = v;
    if (v < 0x6ee) return;
    {
        int r = Ov193_FindTarget(*state, 0);
        state[6] = r;
        if (r != 0) {
            VEC_Subtract((void *)(r + 0x74), (void *)(*state + 0x74), buf);
            state[4] = func_020050b4(buf[0], buf[2]);
        }
    }
    ((struct hw60 *)(*state + 0x60))->hi &= ~0x82;
    Ov107_PostTagUpdate(*state, 0, 0);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov193_stRandDelayInRange);
}
