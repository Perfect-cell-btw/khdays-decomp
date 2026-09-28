extern void Ov107_StartAnim(int a, int b, int c);
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov140_TransformScaleUntilObjectReady(void);

struct sbit1 { unsigned char b : 1; };

void Ov140_Action6IfHitFlagsSet(int *node) {
    int *state = (int *)node[1];
    int s = *state;
    if (((struct sbit1 *)(s + 0x17a))->b == 0 && ((struct sbit1 *)(s + 0x17c))->b == 0)
        return;
    {
        unsigned short hw60 = *(unsigned short *)(s + 0x60);
        *(unsigned short *)(s + 0x60) =
            (hw60 & ~0xff00) | (((((unsigned int)hw60 << 0x10) >> 0x18 | 0x40) << 0x18) >> 0x10);
    }
    Ov107_StartAnim(*(int *)(*state + 0x390), 2, 0);
    Ov107_PostTagUpdate(*state, 7, 0);
    Ov107_BuildAndSendUpdate(*state, 0x11f, 6, state[0x13]);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov140_TransformScaleUntilObjectReady);
}
