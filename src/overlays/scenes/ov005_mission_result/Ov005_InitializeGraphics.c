/* Black both screens, clear VRAM, and configure the overlay's graphics banks. */

#include "game/engine.h"

extern void GX_SetBankForLCDC(int);
extern void MIi_CpuClearFast(unsigned int,void *,unsigned int);
extern void GX_DisableBankForLCDC(void);
extern void Ov005_SetVramBankPlan(void);
extern void Ov005_ConfigureBackgroundControls(void);
extern void Ov005_ConfigureBackgroundPriorities(void);
void Ov005_InitializeGraphics(void) {
    SetMasterBrightnessMain(-16);
    SetMasterBrightnessSub(-16);
    Gfx_Reset2DEngines();
    GX_SetBankForLCDC(0x1ff);
    MIi_CpuClearFast(0,(void *)0x06800000,0xa4000);
    GX_DisableBankForLCDC();
    Ov005_SetVramBankPlan();
    Ov005_ConfigureBackgroundControls();
    Ov005_ConfigureBackgroundPriorities();
    *(volatile unsigned short *)0x04000304 &= ~0x8000;
    *(volatile unsigned int *)0x04000000 &= ~0x1f00;
    *(volatile unsigned int *)0x04001000 &= ~0x1f00;
}
