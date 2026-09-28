extern int data_ov002_0207fa00;

void Ov002_SetRootWord8a28(int arg0, int arg1) {
    *(int *)(*(int *)&data_ov002_0207fa00 + arg0 * 4 + 0x8a28) = arg1;
}
