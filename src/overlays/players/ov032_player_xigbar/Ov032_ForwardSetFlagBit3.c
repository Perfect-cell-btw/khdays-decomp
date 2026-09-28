/* Panel callback (+0x664+0x0c): sets flag bit 3 on the bound object at +0x2c2c, if any. */

extern void func_ov022_02089584(void *p);

void Ov032_ForwardSetFlagBit3(char *base) {
    void *p = *(void **)(base + 0x2c2c);
    if (p == 0) return;
    func_ov022_02089584(p);
}
