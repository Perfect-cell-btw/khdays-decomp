/* Resolve param_2 (mode 0xf) into the +0x2c slot, then start the object with
 * Ov002_RebindSlotToCell; always returns 1. */
extern int Archive_LoadFile(int a, int b);
extern void Ov002_RebindSlotToCell(int a, int b, int c, int d);

int Ov002_Slot_LoadCellFile(int param_1, int param_2) {
    *(int *)(param_1 + 0x2c) = Archive_LoadFile(param_2, 0xf);
    Ov002_RebindSlotToCell(param_1, 1, 1, 0);
    return 1;
}
