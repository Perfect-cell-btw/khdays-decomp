extern void Ov002_NotifyAllEventEntries(void);
extern void MIi_CpuClear16(int value, void *dst, int size);
extern char *data_ov002_0207fa04;
/* Run the pre-step, then (unless already in state 2) enter it and blank the 8-byte id array. */
void Ov002_EnterState2AndBlankIds(void) {
    int ctx = (int)data_ov002_0207fa04;
    Ov002_NotifyAllEventEntries();
    if ((*(unsigned short *)ctx & 2) != 0) {
        return;
    }
    *(unsigned short *)ctx = 2;
    MIi_CpuClear16(0xffff, (void *)(ctx + 2), 8);
}
