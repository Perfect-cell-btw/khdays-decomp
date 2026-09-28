extern int data_ov002_0207fa14;

void Ov002_SetPendingSlotFlag(int arg0) {
    int p = *(int *)&data_ov002_0207fa14;
    *(unsigned char *)(p + 0x54) |= 1 << arg0;
}
