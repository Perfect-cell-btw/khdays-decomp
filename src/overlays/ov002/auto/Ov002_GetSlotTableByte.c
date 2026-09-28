extern int data_ov002_0207fa10;

int Ov002_GetSlotTableByte(int arg0) {
    if (arg0 >= 0) {
        return *(signed char *)(*(int *)&data_ov002_0207fa10 + arg0 + 0x2f);
    }
    return -1;
}
