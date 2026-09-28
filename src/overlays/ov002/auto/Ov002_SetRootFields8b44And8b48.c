extern int data_ov002_0207fa00;

void Ov002_SetRootFields8b44And8b48(int arg0, int arg1) {
    int base = *(int *)&data_ov002_0207fa00 + 0x8000;
    *(int *)(base + 0xb44) = arg0;
    *(int *)(base + 0xb48) = arg1;
}
