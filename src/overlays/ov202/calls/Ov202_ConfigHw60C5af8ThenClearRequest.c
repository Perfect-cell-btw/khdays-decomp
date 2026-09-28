extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *value);

struct ov202_Hw60 {
    unsigned short lo : 8;
    unsigned short hi : 8;
};

struct ov202_LowByteFlags {
    unsigned bits : 8;
};

void Ov202_ConfigHw60C5af8ThenClearRequest(int *node) {
    int *state = (int *)node[1];
    ((struct ov202_Hw60 *)(*state + 0x60))->hi &= ~1;

    *(unsigned short *)(*state + 0x1ae) |= 3;

    {
        unsigned short hw60 = *(unsigned short *)(*state + 0x60);
        *(unsigned short *)(*state + 0x60) =
            (hw60 & ~0xff00) | (((((unsigned int)hw60 << 0x10) >> 0x18 | 0x86) << 0x18) >> 0x10);
    }

    ((struct ov202_LowByteFlags *)(*(int *)(*state + 0x38c) + 8))->bits &= ~1;
    Ov107_BuildAndSendUpdate(*state, 0, 0x4a, state[16]);
    *(signed char *)(*state + 0x1c7) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
}
