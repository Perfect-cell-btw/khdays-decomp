extern void Ov107_StartAnim();
extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov164_AiTrackOffsetTick(void);
void Ov164_stateSetFlagEffect(int *node) {
    int *state = (int *)node[1];
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x40) << 0x18) >> 0x10));
    }
    Ov107_StartAnim(*(int *)(*state + 0x3c8), 0, 0);
    Ov107_PostTagUpdate(*state, 4, 0);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov164_AiTrackOffsetTick);
}
