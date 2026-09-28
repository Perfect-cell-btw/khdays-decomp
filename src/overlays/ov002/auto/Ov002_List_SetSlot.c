extern int data_ov002_0207fa20;

void Ov002_List_SetSlot(int arg0, int arg1) {
    *(int *)(*(int *)((char *)&data_ov002_0207fa20 + 4) + arg1 * 4 + 0x6c) = arg0;
}
