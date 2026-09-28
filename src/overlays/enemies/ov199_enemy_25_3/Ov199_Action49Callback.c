extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov199_TimerGateHw60FlipThenAdvance(void);

struct ov147_LowByteFlags { unsigned bits : 8; };

void Ov199_Action49Callback(int *node) {
    int *state = (int *)node[1];

    {
        unsigned short hw60 = *(unsigned short *)(*state + 0x60);
        *(unsigned short *)(*state + 0x60) =
            (hw60 & ~0xff00) | (((((unsigned int)hw60 << 0x10) >> 0x18 | 0x46) << 0x18) >> 0x10);
    }

    *(unsigned short *)(*state + 0x1ae) |= 1;
    ((struct ov147_LowByteFlags *)(*(int *)(*state + 0x38c) + 8))->bits &= ~1;
    Ov107_BuildAndSendUpdate(*state, 0, 0x49, *state + 0x74);
    state[0x10] = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov199_TimerGateHw60FlipThenAdvance);
}
