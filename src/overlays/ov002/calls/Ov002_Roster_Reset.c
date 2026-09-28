/* Resets the roster record (valid, no members). */

extern void MIi_CpuClear16();
extern int data_ov002_0207fa04;

void Ov002_Roster_Reset(void) {
    int p = *(int *)&data_ov002_0207fa04;
    *(unsigned short *)p = 1;
    MIi_CpuClear16(0xffff, p + 2, 8);
}
