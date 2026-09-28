extern void Ov107_StartAnim();
extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov204_TransformScaleAdvanceIfZero(void);
void Ov204_AiEnterAnim6WithSpeed(int *node) {
    int v = *(int *)(*node + 0x2c) * 0x1e;
    int *state = (int *)node[1];
    int result = v / 5;
    state[0xf] = result;
    Ov107_StartAnim(*(int *)(*state + 0x390), 1, 0, result);
    Ov107_PostTagUpdate(*state, 6, 0);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov204_TransformScaleAdvanceIfZero);
}
