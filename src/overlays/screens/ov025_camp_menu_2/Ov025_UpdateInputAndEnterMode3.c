/* Ov025_UpdateInputAndEnterMode3 -- advance the menu's page-slide and reset its offset, ov008.
 * Ticks the two page animators (Ov025_HandlerA_Call2/020514cc with base+0x959c/0x95a0); once
 * the swap-active bit (bit2 of base+0x95f0) clears it is done. While still swapping, zeroes the
 * scroll offset (base+0x95f8), re-scrolls (Ov025_SetCtxField95fc(1)) and re-arms the label
 * rebuild (Ov025_SetCtxField95cc(3)). */
extern void Ov025_HandlerA_Call2(int a);
extern void Ov025_HandlerB_Call2(int a);
extern void Ov025_SetCtxField95fc(int a);
extern void Ov025_SetCtxField95cc(int a);
extern int  data_ov025_020b5744[];

void Ov025_UpdateInputAndEnterMode3(void) {
    Ov025_HandlerA_Call2(*(int *)(data_ov025_020b5744[1] + 0x959c));
    Ov025_HandlerB_Call2(*(int *)(data_ov025_020b5744[1] + 0x95a0));
    if (((unsigned int)*(int *)(data_ov025_020b5744[1] + 0x95f0) << 0x1d >> 0x1f) == 0) {
        return;
    }
    *(int *)(data_ov025_020b5744[1] + 0x95f8) = 0;
    Ov025_SetCtxField95fc(1);
    Ov025_SetCtxField95cc(3);
}
