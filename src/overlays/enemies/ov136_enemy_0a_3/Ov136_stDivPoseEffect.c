extern void Ov107_PostTagUpdate();
extern void Ov107_StartAnim();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov136_ChaseTick(void);
void Ov136_stDivPoseEffect(int *node) {
    int v = *(int *)(*node + 0x2c) * 0x1e;
    int *state = (int *)node[1];
    state[5] = v / 15;
    Ov107_PostTagUpdate(*state, 2, 1, v);
    state[12] = 0;
    Ov107_StartAnim(*(int *)(*state + 0x3a0), 0, 1);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov136_ChaseTick);
}
