extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov151_TimerAcquireTargetAngleThenAdvance(void);

struct hw60 { unsigned short lo : 8, hi : 8; };
struct ov151_LowByteFlags { unsigned bits : 8; };

void Ov151_Action48Callback(int *node) {
    int *state = (int *)node[1];

    {
        unsigned short hw60 = *(unsigned short *)(*state + 0x60);
        *(unsigned short *)(*state + 0x60) =
            (hw60 & ~0xff00) | (((((unsigned int)hw60 << 0x10) >> 0x18 | 0x80) << 0x18) >> 0x10);
    }
    ((struct hw60 *)(*state + 0x60))->hi &= ~2;
    *(unsigned short *)(*state + 0x1ae) |= 1;
    ((struct ov151_LowByteFlags *)(*(int *)(*state + 0x388) + 8))->bits &= ~1;
    state[0xc] = 0;
    Ov107_BuildAndSendUpdate(*state, 0, 0x48, state[0x11]);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov151_TimerAcquireTargetAngleThenAdvance);
}
