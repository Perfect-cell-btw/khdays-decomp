extern int data_ov002_0207fa00;

int Ov002_IsSessionOpen(void) {
    int p = *(int *)&data_ov002_0207fa00;
    if (p == 0) {
        return 0;
    }
    return *(int *)(p + 0x8bcc) != -1;
}
