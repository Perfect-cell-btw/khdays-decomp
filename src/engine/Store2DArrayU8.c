extern int data_0204c690;

void Store2DArrayU8(int arg0, int arg1, char arg2) {
    *(unsigned char *)((char *)&data_0204c690 + arg0 * 0x104 + arg1) = arg2;
}
