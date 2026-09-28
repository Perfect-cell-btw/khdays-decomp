extern int data_ov002_0207fa00;

void Ov002_SetRootField8b40(void) {
    *(char *)(*(int *)&data_ov002_0207fa00 + 0x8b40) = 1;
}
