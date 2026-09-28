/* State step: posts pose 3, faces the target when one is set and installs the eased-pose step. */

extern void Ov107_PostTagUpdate();
extern void VEC_Subtract();
extern int func_020050b4();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov269_stEasePoseCheckFlags(void);
void Ov269_stateAnimAimAtTarget(int *node) {
    int *state = (int *)node[1];
    Ov107_PostTagUpdate(*state, 3, 0);
    if (state[0xe] != 0) {
        int buf[3];
        int a;
        VEC_Subtract(state[0xe] + 0x190, *state + 0xb0, buf);
        a = func_020050b4(buf[0], buf[2]);
        state[4] = a;
        state[3] = a;
    }
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov269_stEasePoseCheckFlags);
}
