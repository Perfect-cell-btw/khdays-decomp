extern void Ov107_StartAnim();
extern void Ov107_PostTagUpdate();
extern void Ov107_BuildAndSendUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov140_TransformScaleNodeVectorThenAdvance(void);
void Ov140_stateSetFlagEffect(int *node) {
    int *state = (int *)node[1];
    {
        int v = *(int *)(*node + 0x2c) * 0x1e;
        state[4] = v / 5;
    }
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x40) << 0x18) >> 0x10));
    }
    Ov107_StartAnim(*(int *)(*state + 0x390), 1, 0);
    Ov107_PostTagUpdate(*state, 6, 0);
    Ov107_BuildAndSendUpdate(*state, 0x11f, 7, state[0x13]);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov140_TransformScaleNodeVectorThenAdvance);
}
