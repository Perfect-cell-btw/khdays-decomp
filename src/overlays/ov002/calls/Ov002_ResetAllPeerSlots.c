/* Reset all 0x20 peer slots: notify each as 0x1000|slot and clear its byte at +0x22c. */

extern int data_ov002_0207fa04;
extern void Ov002_DestroyEventSlot(int id);

void Ov002_ResetAllPeerSlots(void) {
    char *ctx = (char *)*(int *)&data_ov002_0207fa04;
    int i;

    for (i = 0; i < 0x20; i++) {
        Ov002_DestroyEventSlot(0x1000 | i);
        ctx[i + 0x22c] = 0;
    }
}
