/* Opens the two resources named by gOv023UiSgBgPath / gOv023UiSgIconPath (mode 0xe),
 * binds the first into the descriptor at +0xc and registers it as display 5 with parameters
 * 0x15 / 2, then stores the second handle at +0. */
extern int Archive_LoadFile(char *name, int mode);
extern void Res_LoadSpriteSet(char *dst, int h, int a, int b, int c);
extern void DispatchByPartType(int a, int b, int c, int d, int e, int f);
extern int AllocAndRegisterOrFree(char *dst, char *name, int mode);
extern char gOv023UiSgBgPath[];
extern char gOv023UiSgIconPath[];

void Ov023_Ov027_LoadGraphics(char *self) {
    int zero = 0;
    *(int *)(self + 4) = Archive_LoadFile(gOv023UiSgBgPath, 0xe);
    Res_LoadSpriteSet(self + 0xc, *(int *)(self + 4), zero, zero, zero);
    DispatchByPartType(5, *(int *)(self + 0xc), *(int *)(self + 0x10), *(int *)(self + 0x14),
                  0x15, 2);
    *(int *)self = AllocAndRegisterOrFree(self + 8, gOv023UiSgIconPath, 0xe);
}
