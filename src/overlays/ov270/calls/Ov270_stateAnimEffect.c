extern void Ov107_PostTagUpdate();
extern void Ov107_StartAnim();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov270_AiTrackOffsetUntilAnimEnd_3(void);
void Ov270_stateAnimEffect(int *node) {
    int *state = (int *)node[1];
    {
        int v = *(int *)(*node + 0x2c) * 0x1e;
        state[5] = v / 3;
    }
    Ov107_PostTagUpdate(*state, 0xe, 0);
    Ov107_StartAnim(*(int *)(*state + 0x3d0), 6, 0);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov270_AiTrackOffsetUntilAnimEnd_3);
}
