/* Ov025_Dma0HookA -- run the DMA0 completion hook, but only while both 2-bit state fields of
 * the word at +0xc (bits 0..1 and bits 2..3) are zero. Both are SIGNED bitfields -- that is the
 * ROM's `lsl ; asrs` pair; unsigned fields would give `lsl ; lsrs`. */
extern int Ov025_GetPageA(void);
extern void func_ov025_020afccc(void);

struct Ov025Bits { int b01 : 2, b23 : 2, rest : 28; };

void Ov025_Dma0HookA(void) {
    int ctx = Ov025_GetPageA();
    if (((struct Ov025Bits *)(ctx + 0xc))->b01 != 0) {
        return;
    }
    if (((struct Ov025Bits *)(ctx + 0xc))->b23 != 0) {
        return;
    }
    func_ov025_020afccc();
}
