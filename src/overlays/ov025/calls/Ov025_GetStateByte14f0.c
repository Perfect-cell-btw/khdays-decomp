extern int Ov025_GetPageA();

unsigned char Ov025_GetStateByte14f0(int arg0) {
    int b = Ov025_GetPageA();
    return *(unsigned char *)(b + arg0 + 0x14f0);
}
