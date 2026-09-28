extern int data_ov002_0207fa00;

void Ov002_World_AddStat(int arg0, int arg1) {
    *(int *)(*(int *)&data_ov002_0207fa00 + 0x8d84 + arg1 * 4) += arg0;
}
