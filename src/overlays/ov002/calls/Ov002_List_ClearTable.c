/* Clears the object list's 0x100-byte table. */

extern void INITi_CpuClear32_0x01ff86fc();
extern int data_ov002_0207fa20;

void Ov002_List_ClearTable(void) {
    INITi_CpuClear32_0x01ff86fc(0, *(int *)((char *)&data_ov002_0207fa20 + 4) + 0x7c, 0x100);
}
