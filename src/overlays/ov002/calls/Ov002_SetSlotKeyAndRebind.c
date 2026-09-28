/* Store param_2 at +0x2c, then (re)initialize the object via Ov002_RebindSlotToCell. */
extern void Ov002_RebindSlotToCell(int a, int b, int c, int d);

void Ov002_SetSlotKeyAndRebind(int param_1, int param_2, int param_3) {
    *(int *)(param_1 + 0x2c) = param_2;
    Ov002_RebindSlotToCell(param_1, 0, param_3, 0);
}
