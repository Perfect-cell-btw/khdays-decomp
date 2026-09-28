/* Sets bit 7 and clears bit 0 of the high flag byte, then clears the step handler. */

extern void SetIndexedSlot(int self, int idx, int cb);

void Ov283_EnterRecoverPose(int param_1) {
    int *node = *(int **)(param_1 + 4);
    unsigned short hw60;
    hw60 = *(unsigned short *)(*node + 0x60);
    *(unsigned short *)(*node + 0x60) =
        (hw60 & ~0xff00) | (((((unsigned int)hw60 << 0x10) >> 0x18 | 0x80) << 0x18) >> 0x10);
    hw60 = *(unsigned short *)(*node + 0x60);
    *(unsigned short *)(*node + 0x60) =
        (hw60 & ~0xff00) | ((unsigned int)(unsigned short)(((unsigned int)hw60 << 0x10) >> 0x18 & 0xfffffffe) << 0x18 >> 0x10);
    SetIndexedSlot(param_1, *(signed char *)((char *)param_1 + 0x20), 0);
}
