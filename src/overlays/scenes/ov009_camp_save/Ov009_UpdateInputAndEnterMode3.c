/* Ov009_UpdateInputAndEnterMode3 -- advance the menu's page-slide and reset its offset, ov008.
 * Ticks the two page animators (Ov009_HandlerA_Call2/020514cc with base+0x959c/0x95a0); once
 * the swap-active bit (bit2 of base+0x95f0) clears it is done. While still swapping, zeroes the
 * scroll offset (base+0x95f8), re-scrolls (Ov009_SetCtxField95fc(1)) and re-arms the label
 * rebuild (Ov009_SetCtxField95cc(3)). */
extern void Ov009_HandlerA_Call2(int a);
extern void Ov009_HandlerB_Call2(int a);
extern void Ov009_SetCtxField95fc(int a);
extern void Ov009_SetCtxField95cc(int a);
extern int  data_ov009_020563e4[];

void Ov009_UpdateInputAndEnterMode3(void) {
    Ov009_HandlerA_Call2(*(int *)(data_ov009_020563e4[1] + 0x959c));
    Ov009_HandlerB_Call2(*(int *)(data_ov009_020563e4[1] + 0x95a0));
    if (((unsigned int)*(int *)(data_ov009_020563e4[1] + 0x95f0) << 0x1d >> 0x1f) == 0) {
        return;
    }
    *(int *)(data_ov009_020563e4[1] + 0x95f8) = 0;
    Ov009_SetCtxField95fc(1);
    Ov009_SetCtxField95cc(3);
}
