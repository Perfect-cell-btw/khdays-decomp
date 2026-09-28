/* Full link reset: tear the slots down, reset the peers, blank the 8-byte id array to 0xffff and
 * put the state word back to 1. */

extern int data_ov002_0207fa04;
extern void Ov002_ResetAllSlots(void);
extern void Ov002_ResetAllPeerSlots(void);
extern void MIi_CpuClear16();

void Ov002_ResetLinkState(void) {
    int p = *(int *)&data_ov002_0207fa04;
    Ov002_ResetAllSlots();
    Ov002_ResetAllPeerSlots();
    MIi_CpuClear16(0xffff, p + 2, 8);
    *(unsigned short *)p = 1;
}
