/* Stamps the cell block into the first tile area (+0x120). */

extern int data_ov002_0207f638;
extern int Ov002_StampCellBlock();

int Ov002_StampCellBlockA(int arg0) {
    return Ov002_StampCellBlock(*(int *)(*(int *)(*(int *)&data_ov002_0207f638 + 0x18) + 0x14) + 0x120, arg0);
}
