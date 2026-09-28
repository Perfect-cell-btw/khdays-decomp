extern int data_ov002_0207fa00;

int Ov002_World_IsFlagBitSet(int arg0) {
    return (*(unsigned char *)(*(int *)&data_ov002_0207fa00 + 0x8c98) & (1 << arg0)) != 0;
}
