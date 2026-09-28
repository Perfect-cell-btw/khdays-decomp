extern int data_ov002_0207fa00;

void Ov002_World_ClearByte8C98(void) {
    *(char *)(*(int *)&data_ov002_0207fa00 + 0x8c98) = 0;
}
