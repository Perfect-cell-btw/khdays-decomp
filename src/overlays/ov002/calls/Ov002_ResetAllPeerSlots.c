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
