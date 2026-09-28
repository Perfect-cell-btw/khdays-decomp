/* The argument address is built in two steps -- a hoisted `base = data + 0x2d94` and
 * `base + 0x14` at the call -- because the ROM splits it (add #0x194 / add #0x2c00 /
 * add #0x14) and the single `+ 0x2da8` form is 4 B short. */
extern void Ov075_StartSequenceSlot(int p);
extern void Ov075_TickChargeStates(int self, int p, int c);
extern int data_ov075_020b9e20;

void Ov075_ForwardWithHeaderOffset(int self, int a, int b) {
    int base = *(int *)&data_ov075_020b9e20 + 0x2d94;
    if (*(int *)(self + 0x6bc) == 0x2f &&
        (*(int *)(self + 0x7b0) == 0 || *(int *)(self + 0x7b0) == 0xc000)) {
        Ov075_StartSequenceSlot(base + 0x14);
    }
    Ov075_TickChargeStates(self, a + 0x14, b);
}
