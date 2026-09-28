/* Ov009_UpdateInputAndEnterMode8 -- advance the menu's simple page-slide one step, ov008.
 * Ticks the two page animators (Ov009_HandlerA_Call2/020514cc with their scroll accumulators
 * at base+0x959c/0x95a0); once the swap-active bit (bit2 of base+0x95f0) clears it is done,
 * otherwise re-arms the label rebuild (Ov009_SetCtxField95cc(8)). */
extern void Ov009_HandlerA_Call2(int a);
extern void Ov009_HandlerB_Call2(int a);
extern void Ov009_SetCtxField95cc(int a);
extern int  data_ov009_020563e4[];

void Ov009_UpdateInputAndEnterMode8(void) {
    Ov009_HandlerA_Call2(*(int *)(data_ov009_020563e4[1] + 0x959c));
    Ov009_HandlerB_Call2(*(int *)(data_ov009_020563e4[1] + 0x95a0));
    if (((unsigned int)*(int *)(data_ov009_020563e4[1] + 0x95f0) << 0x1d >> 0x1f) == 0) {
        return;
    }
    Ov009_SetCtxField95cc(8);
}
