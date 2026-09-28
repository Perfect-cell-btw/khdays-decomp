extern int Ov025_MapCodeToSlotIndex();
extern int data_ov025_020b5744;

void Ov025_ClearSlotBit(int arg0) {
    unsigned int idx = Ov025_MapCodeToSlotIndex(arg0);
    if (idx == 0xffffffff) return;
    *(unsigned char *)(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x963c) &= ~(1 << idx);
}
