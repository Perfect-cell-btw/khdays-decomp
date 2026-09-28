/* Clears a fixed-size block of the root field object. */

extern void MI_CpuFill8();
extern int data_ov002_0207fa00;

void Ov002_ClearRosterRow(void) {
    MI_CpuFill8(*(int *)&data_ov002_0207fa00 + 0x8b7c, 0, 0x2c);
}
