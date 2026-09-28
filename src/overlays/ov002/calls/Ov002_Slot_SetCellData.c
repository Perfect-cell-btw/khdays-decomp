extern int Ov002_RebindSlotToCell();

int Ov002_Slot_SetCellData(int arg0, int arg1) {
    *(int *)(arg0 + 0x2c) = arg1;
    Ov002_RebindSlotToCell(arg0, 0);
    return 1;
}
