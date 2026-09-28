/* Selects the sub text-BG3 display mode and sets sub-engine BG3CNT. */

extern void SetSubEngineGraphicsModeFromTable(void *ptr);
extern char data_02041eec;

void Bg_SetSubBg3TextControl(int arg0, int arg1, int arg2, int arg3) {
    volatile unsigned short *reg_bg3cnt_b = (volatile unsigned short *)0x0400100e;

    SetSubEngineGraphicsModeFromTable(&data_02041eec);
    *reg_bg3cnt_b = (*reg_bg3cnt_b & 0x43) | (arg0 << 14) | (arg1 << 7) | (arg2 << 8) | (arg3 << 2);
}
