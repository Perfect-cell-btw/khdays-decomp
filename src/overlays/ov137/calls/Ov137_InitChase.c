/* c634 init of the ov137 enemy: reset owner status bytes (+0x1c6=0, +0x1c7=-1), drop bit 0 of
 * the +0x384 item's +8 word, cache owner+0xb0 / owner+0x74 into state[0x13..0x14], keep the
 * owner's +0x1b0 halfword as a byte at +0x56, raise bits 1-2 of the +0x60 high byte and arm the
 * three phase callbacks (slots 1/0/2). */
struct bf { unsigned b : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov137_SetHwFlagsAndDispatch(void);
extern void Ov137_AiDispatchAction(void);
extern void Ov137_AdvanceMotionPublish(void);

void Ov137_InitChase(int *node) {
    int *state = (int *)node[1];
    *(signed char *)(*state + 0x1c6) = 0;
    *(signed char *)(*state + 0x1c7) = -1;
    ((struct bf *)(*(int *)(*state + 0x384) + 8))->b &= ~1;
    state[0x13] = *state + 0xb0;
    state[0x14] = *state + 0x74;
    *(unsigned char *)((char *)state + 0x56) = *(unsigned short *)(*state + 0x100 + 0xb0);
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 6) << 0x18) >> 0x10));
    }
    SetIndexedSlot(node, 1, Ov137_SetHwFlagsAndDispatch);
    SetIndexedSlot(node, 0, Ov137_AiDispatchAction);
    SetIndexedSlot(node, 2, Ov137_AdvanceMotionPublish);
}
