extern void MI_CpuFill8();
extern int data_ov002_0207f9a0;

void Ov002_ClearPlayerFlagRecords(void) {
    MI_CpuFill8(&data_ov002_0207f9a0, 0, 0x50);
}
