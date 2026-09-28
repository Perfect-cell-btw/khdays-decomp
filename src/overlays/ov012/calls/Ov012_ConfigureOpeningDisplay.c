extern void SetMasterBrightnessMain(int level);
extern void SetMasterBrightnessSub(int level);
extern void Gfx_Reset2DEngines(void);
extern void Ov024_RunDisplayTeardownSteps(int doMain, int doSub);
extern void GX_SetGraphicsMode(int a, int b, int c);
extern void GX_SetBankForBG(int bank);
extern void GX_SetBankForBGExtPltt(int bank);

void Ov012_ConfigureOpeningDisplay(void) {
    SetMasterBrightnessMain(-0x10);
    SetMasterBrightnessSub(-0x10);
    Gfx_Reset2DEngines();
    Ov024_RunDisplayTeardownSteps(0, 1);
    GX_SetGraphicsMode(1, 0, 0);
    GX_SetBankForBG(3);
    GX_SetBankForBGExtPltt(0);
    {
        volatile unsigned short *bg = (volatile unsigned short *)0x04000008;

        bg[0] = bg[0] & 0x43 | 0x84;
        bg[1] = bg[1] & 0x43 | 0x290;
        bg[2] = bg[2] & 0x43 | 0x4a0;
        *(volatile unsigned int *)0x04000000 &= ~0x1f00;
        bg[0] = bg[0] & ~3 | 2;
        bg[1] = bg[1] & ~3 | 1;
        bg[2] = bg[2] & ~3;
        *(volatile unsigned short *)0x04000304 &= ~0x8000;
    }
}
