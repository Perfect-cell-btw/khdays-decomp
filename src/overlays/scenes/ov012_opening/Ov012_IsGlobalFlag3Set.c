extern int data_ov012_0205cb20;

int Ov012_IsGlobalFlag3Set(void) {
    return (*(unsigned short *)(data_ov012_0205cb20 + 2) & 8) != 0;
}
