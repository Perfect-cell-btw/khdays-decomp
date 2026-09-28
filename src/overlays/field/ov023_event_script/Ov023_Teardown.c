/* Ov023_Teardown -- ov023 teardown. In global mode 4 only: hand the screens back
 * (GX_SetGraphicsMode), map VRAM bank 8 to the LCDC, wipe 0xa4000 bytes of it from 0x06800000, and
 * release the sound mutex. Then drop the scene request (StoreToGlobalPtr4FieldE4IfSet(0)). */
extern int LoadGlobalU16At0(void);
extern void GX_SetGraphicsMode(int a, int b, int c);
extern void GX_SetBankForLCDC(int bank);
extern void MIi_CpuClearFast(int value, void *dst, int size);
extern void GX_DisableBankForLCDC(void);
extern void StoreToGlobalPtr4FieldE4IfSet(int a);

void Ov023_Teardown(void) {
    if (LoadGlobalU16At0() == 4) {
        GX_SetGraphicsMode(1, 0, 1);
        GX_SetBankForLCDC(8);
        MIi_CpuClearFast(0, (void *)0x06800000, 0xa4000);
        GX_DisableBankForLCDC();
    }
    StoreToGlobalPtr4FieldE4IfSet(0);
}
