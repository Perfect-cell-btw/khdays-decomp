/* Reset the fixed-layout scratch block at (*global)+0x104 and stash param_1 at +0xd. */
extern int data_ov002_0207fa10;

void Ov002_Link_RequestSave(int param_1) {
    int base = *(int *)&data_ov002_0207fa10;
    *(unsigned char *)(base + 0x104) = 0;
    *(unsigned char *)(base + 0x105) = 0;
    *(int *)(base + 0x108) = 0;
    *(int *)(base + 0x10c) = 0;
    *(unsigned char *)(base + 0xd) = param_1;
}
