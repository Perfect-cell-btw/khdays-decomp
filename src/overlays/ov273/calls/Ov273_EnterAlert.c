/* Raise the "alert" pose (hw60 high-byte bit 0x80) and register the alert think callback, but only
 * while the flag at *node[2] is clear. */
extern void SetIndexedSlot(int self, int idx, void *cb);
extern void Ov273_RegroupTick(void);

void Ov273_EnterAlert(int param_1) {
    int *node = *(int **)(param_1 + 4);
    unsigned short hw60;
    if (*(unsigned char *)node[2] != 0) {
        return;
    }
    hw60 = *(unsigned short *)(*node + 0x60);
    *(unsigned short *)(*node + 0x60) =
        (hw60 & ~0xff00) | (((((unsigned int)hw60 << 0x10) >> 0x18 | 0x80) << 0x18) >> 0x10);
    SetIndexedSlot(param_1, *(signed char *)((char *)param_1 + 0x20), &Ov273_RegroupTick);
}
