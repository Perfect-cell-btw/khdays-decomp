struct bf { unsigned b : 8; };
struct hw60 { unsigned short lo : 8, hi : 8; };
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov284_stSetDispFlags82(void);
extern void Ov284_SetFlag1aeThenAction7(void);
extern void Ov284_SetReadyBitThenAdvance(void);
extern void Ov284_BeginAnim3AndReset(void);
extern void Ov284_DeathEntry(void);
extern void Ov284_AiEnterAnim1AndLock(void);
extern void Ov284_AiSetStanceFlags86AndFinish(void);

void Ov284_DispatchSubStateByte(int *node) {
    int *state = (int *)node[1];
    int c = *(signed char *)(*state + 0x1c7);
    if (c != -1) {
        ((struct hw60 *)(*state + 0x60))->hi &= ~0xca;
        *(unsigned short *)(*state + 0x1ae) &= ~0x1;
        ((struct bf *)(*(int *)(*state + 0x3a8) + 8))->b &= ~1;
        *(signed char *)(*state + 0x1c6) = *(signed char *)(*state + 0x1c7);
        switch (*(signed char *)(*state + 0x1c6)) {
        case 0:
            SetIndexedSlot(node, 1, Ov284_stSetDispFlags82);
            break;
        case 1:
            SetIndexedSlot(node, 1, Ov284_SetFlag1aeThenAction7);
            break;
        case 2:
            SetIndexedSlot(node, 1, Ov284_SetReadyBitThenAdvance);
            break;
        case 7:
            SetIndexedSlot(node, 1, Ov284_BeginAnim3AndReset);
            break;
        case 3:
            SetIndexedSlot(node, 1, Ov284_DeathEntry);
            break;
        case 8:
            SetIndexedSlot(node, 1, Ov284_AiEnterAnim1AndLock);
            break;
        case 9:
            SetIndexedSlot(node, 1, Ov284_AiSetStanceFlags86AndFinish);
            break;
        }
    }
    *(signed char *)(*state + 0x1c7) = -1;
}
