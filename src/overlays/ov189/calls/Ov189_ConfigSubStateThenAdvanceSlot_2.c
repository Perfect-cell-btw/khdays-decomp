struct hw60 { unsigned short lo : 8, hi : 8; };
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov107_StartAnim(int a, int b, int c);
extern void SetIndexedSlot(void *node, int idx, void *value);
extern void Ov189_UpdateRotatingHitAction(void);

void Ov189_ConfigSubStateThenAdvanceSlot_2(int *node) {
    int *state = (int *)node[1];
    Ov107_PostTagUpdate(*state, 5, 0);
    Ov107_StartAnim(*(int *)(*state + 0x3c0), 0, 0);
    { unsigned short *p = (unsigned short *)(*state + 0x60); unsigned int u = *p;
      *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x40) << 0x18) >> 0x10)); }
    state[6] = 0;
    *(unsigned char *)((char *)state + 0x3c) = 0;
    *(unsigned char *)((char *)state + 0x3d) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov189_UpdateRotatingHitAction);
}
