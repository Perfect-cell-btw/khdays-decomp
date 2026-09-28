/* Ov025_Dma0HookB -- twin of Ov025_Dma0HookA for the other DMA0 hook. */
extern int Ov025_GetPageA(void);
extern void func_ov025_020afcbc(void);

struct Ov025Bits { int b01 : 2, b23 : 2, rest : 28; };

void Ov025_Dma0HookB(void) {
    int ctx = Ov025_GetPageA();
    if (((struct Ov025Bits *)(ctx + 0xc))->b01 != 0) {
        return;
    }
    if (((struct Ov025Bits *)(ctx + 0xc))->b23 != 0) {
        return;
    }
    func_ov025_020afcbc();
}
