/* Clears page A (0x2b0 bytes). */

extern int Ov025_GetPageA();
extern void MI_CpuFill8();

void Ov025_PageA_ResetLarge(int arg0) {
    MI_CpuFill8(Ov025_GetPageA(arg0), 0, 0x2b0);
}
