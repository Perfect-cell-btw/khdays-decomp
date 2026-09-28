extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *value);

struct ov123_Hw60 {
    unsigned short lo : 8;
    unsigned short hi : 8;
};

struct ov123_LowByteFlags {
    unsigned bits : 8;
};

void Ov123_ConfigHw60Action49ThenAdvance(int *node) {
    int *state = (int *)node[1];
    ((struct ov123_Hw60 *)(*state + 0x60))->hi &= ~1;

    {
        unsigned short hw60 = *(unsigned short *)(*state + 0x60);
        *(unsigned short *)(*state + 0x60) =
            (hw60 & ~0xff00) | (((((unsigned int)hw60 << 0x10) >> 0x18 | 0x86) << 0x18) >> 0x10);
    }

    ((struct ov123_LowByteFlags *)(*(int *)(*state + 0x388) + 8))->bits &= ~1;
    Ov107_BuildAndSendUpdate(*state, 0, 0x49, state[5]);
    *(signed char *)(*state + 0x1c7) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
}
