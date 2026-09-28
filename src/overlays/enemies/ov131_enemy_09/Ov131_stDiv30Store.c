/* ov node state callback: stores object[+0x2c]*30/30 into a state field (magic-multiply divide),
 * then advances/guards the node state slot. */

extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov131_ReactWhenTargetInReach(void);

void Ov131_stDiv30Store(int *param_1) {
    int v = *(int *)(*param_1 + 0x2c) * 0x1e;
    int *state = (int *)param_1[1];
    state[5] = v / 30;
    Ov107_PostTagUpdate(*state, 1, 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 8), Ov131_ReactWhenTargetInReach);
}
