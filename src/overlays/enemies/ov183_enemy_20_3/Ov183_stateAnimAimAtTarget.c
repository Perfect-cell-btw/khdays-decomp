/* State step: posts a pose and, when a target is set, turns the heading toward it; installs the
 * eased-pose step. */

extern void Ov107_PostTagUpdate();
extern void VEC_Subtract();
extern int func_020050b4();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov183_stEasePoseCheckFlags(void);
void Ov183_stateAnimAimAtTarget(int *node) {
    int *state = (int *)node[1];
    Ov107_PostTagUpdate(*state, 8, 0);
    if (state[9] != 0) {
        int buf[3];
        int a;
        VEC_Subtract(state[9] + 0x190, state[1], buf);
        a = func_020050b4(buf[0], buf[2]);
        state[6] = a;
        state[5] = a;
    }
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov183_stEasePoseCheckFlags);
}
