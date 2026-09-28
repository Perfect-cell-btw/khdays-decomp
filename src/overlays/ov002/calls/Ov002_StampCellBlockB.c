extern int data_ov002_0207f638;
extern int Ov002_StampCellBlock();

int Ov002_StampCellBlockB(int arg0) {
    return Ov002_StampCellBlock(*(int *)(*(int *)(*(int *)&data_ov002_0207f638 + 0x18) + 0x14) + 0x380, arg0);
}
