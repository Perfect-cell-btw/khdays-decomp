extern unsigned short data_0204c190;

int Ov003_IsGlobalBit0Set(void) {
    return (data_0204c190 & 1) != 0;
}
