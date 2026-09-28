/* Ov025_UpdateInputAndEnableHalves -- advance the menu's page-swap animation one step, ov008.
 * Ticks the two page animators (Ov025_HandlerA_Call2 / 020514cc); once the swap-active bit
 * (bit2 of base+0x95f0) clears, it is done. While still swapping, refreshes the page contents
 * (Ov025_EnableBothHalves(1)) and re-arms the label rebuild (Ov025_SetCtxField95cc(3)). */
extern void Ov025_HandlerA_Call2(int a);
extern void Ov025_HandlerB_Call2(int a);
extern void Ov025_EnableBothHalves(int a);
extern void Ov025_SetCtxField95cc(int a);
extern int  data_ov025_020b5744[];

void Ov025_UpdateInputAndEnableHalves(void) {
    Ov025_HandlerA_Call2(*(int *)(data_ov025_020b5744[1] + 0x959c));
    Ov025_HandlerB_Call2(*(int *)(data_ov025_020b5744[1] + 0x95a0));
    if (((unsigned int)*(int *)(data_ov025_020b5744[1] + 0x95f0) << 0x1d >> 0x1f) == 0) {
        return;
    }
    Ov025_EnableBothHalves(1);
    Ov025_SetCtxField95cc(3);
}
