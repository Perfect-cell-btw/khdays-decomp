extern void Ov107_BuildAndSendUpdate(int a, int b, int c, int d);
extern void SetIndexedSlot(void *node, int idx, void *value);

struct ov154_Hw60 {
    unsigned short lo : 8;
    unsigned short hi : 8;
};

struct ov154_LowByteFlags {
    unsigned bits : 8;
};

void Ov154_ConfigHw60C5af8ThenClearRequest(int *node) {
    int *state = (int *)node[1];
    ((struct ov154_Hw60 *)(*state + 0x60))->hi &= ~1;

    {
        unsigned short hw60 = *(unsigned short *)(*state + 0x60);
        *(unsigned short *)(*state + 0x60) =
            (hw60 & ~0xff00) | (((((unsigned int)hw60 << 0x10) >> 0x18 | 0x86) << 0x18) >> 0x10);
    }

    *(unsigned short *)(*state + 0x1ae) |= 3;
    ((struct ov154_LowByteFlags *)(*(int *)(*state + 0x388) + 8))->bits &= ~1;
    Ov107_BuildAndSendUpdate(*state, 0, 0x4b, state[2]);
    *(signed char *)(*state + 0x1c7) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
}
