/* Re-enables the BG layers of both engines, resets the brightness, restores the graphics mode and
 * VBlank callback and refreshes the scene. */

typedef unsigned short u16;
typedef unsigned int u32;

extern char *data_0204be08;
extern char data_02042748[16];

extern int LoadGlobalU16At0(void);
extern void G2x_SetBlendBrightness_(u16 *dst, u32 attr, int value);
extern void GX_SetGraphicsMode(u16 param_1, u32 param_2, int param_3);
extern void VBlank_UnregisterCallback(int unused, const char *name);
extern void Ov002_UpdatePanelBlend(void);
extern int Ov106_GetBrightness(void);

/* GBATEK: DISPCNT, main engine. */
#define REG_DISPCNT (*(volatile u32 *)0x04000000)

void Gfx_RestoreAfterPause(void)
{
    char *heap = (&data_0204be08)[1];

    if ((LoadGlobalU16At0() & 8) != 0) {
        REG_DISPCNT = (REG_DISPCNT & 0xffffe0ff) | 0x100;
    } else {
        REG_DISPCNT = (REG_DISPCNT & 0xffffe0ff) | 0x1f00;
    }

    G2x_SetBlendBrightness_((u16 *)0x04000050, 1, 0);

    {
        volatile u32 *subDispCnt = (volatile u32 *)0x04001000;
        u32 attr = (*subDispCnt & 0x1f00) >> 8;
        G2x_SetBlendBrightness_((u16 *)((char *)subDispCnt + 0x50), attr, 0);
    }

    if (*(int *)(heap + 0xe4) != 0) {
        GX_SetGraphicsMode(0xe, 4, 1);
    }

    VBlank_UnregisterCallback(1, data_02042748);
    Ov002_UpdatePanelBlend();

    if (LoadGlobalU16At0() == 0x2a) {
        G2x_SetBlendBrightness_((u16 *)0x04000050, 1, Ov106_GetBrightness());
    }
}
