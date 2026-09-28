/* Ov008_UpdateInputAndEnableHalves -- advance the menu's page-swap animation one step, ov008.
 * Ticks the two page animators (Ov008_HandlerA_Call2 / 020514cc); once the swap-active bit
 * (bit2 of base+0x95f0) clears, it is done. While still swapping, refreshes the page contents
 * (Ov008_EnableBothHalves(1)) and re-arms the label rebuild (Ov008_SetCtxField95cc(3)). */
extern void Ov008_HandlerA_Call2(int a);
extern void Ov008_HandlerB_Call2(int a);
extern void Ov008_EnableBothHalves(int a);
extern void Ov008_SetCtxField95cc(int a);
extern int  data_ov008_02090f04[];

void Ov008_UpdateInputAndEnableHalves(void) {
    Ov008_HandlerA_Call2(*(int *)(data_ov008_02090f04[1] + 0x959c));
    Ov008_HandlerB_Call2(*(int *)(data_ov008_02090f04[1] + 0x95a0));
    if (((unsigned int)*(int *)(data_ov008_02090f04[1] + 0x95f0) << 0x1d >> 0x1f) == 0) {
        return;
    }
    Ov008_EnableBothHalves(1);
    Ov008_SetCtxField95cc(3);
}
