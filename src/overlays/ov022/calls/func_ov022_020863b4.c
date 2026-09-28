extern void Ov002_FreeBufferAndClearStatus(int arg0);

void func_ov022_020863b4(int arg0) {
    Ov002_FreeBufferAndClearStatus(arg0);
    Ov002_FreeBufferAndClearStatus(arg0 + 0x30);
    Ov002_FreeBufferAndClearStatus(arg0 + 0x60);
}
