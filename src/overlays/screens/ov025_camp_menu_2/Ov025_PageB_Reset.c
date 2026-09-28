/* Clears page B's state and binds it to page A's block. */

extern int Ov025_GetPageB();
extern void MI_CpuFill8();
extern int Ov025_PageA_GetBlock1EC();

void Ov025_PageB_Reset(int arg0) {
    int x = Ov025_GetPageB(arg0);
    MI_CpuFill8(x, 0, 0x84);
    *(int *)(x + 0x50) = Ov025_PageA_GetBlock1EC();
}
