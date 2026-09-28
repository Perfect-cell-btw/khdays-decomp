extern void func_ov022_02089584(void *p);

void Ov072_ForwardSetFlagBit3(char *base) {
    void *p = *(void **)(base + 0x2c2c);
    if (p == 0) return;
    func_ov022_02089584(p);
}
