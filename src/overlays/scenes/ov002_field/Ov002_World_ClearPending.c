extern int data_ov002_0207fa00;

void Ov002_World_ClearPending(void) {
    *(int *)(*(int *)&data_ov002_0207fa00 + 0x8d10) = -1;
}
