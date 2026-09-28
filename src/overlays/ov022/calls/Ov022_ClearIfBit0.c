extern void Ov022_ClearByte_2();
void Ov022_ClearIfBit0(unsigned char *arg0) {
    if ((*arg0 & 1) != 0) Ov022_ClearByte_2(arg0);
}
