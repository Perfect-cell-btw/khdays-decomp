extern int data_ov012_0205cb20;

int Ov012_IsGlobalByte8be1Clear(void) {
    return *(unsigned char *)(data_ov012_0205cb20 + 0x8be1) == 0;
}
