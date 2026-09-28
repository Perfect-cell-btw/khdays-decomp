#include "nitro/types.h"
#include "nitro/os.h"
typedef void *OSMessage;

#define NULL ((void *)0)
#define HW_MAIN_MEM 0x02000000

#define offsetof(type, member) ((u32)&(((type *)0)->member))

#define GX_DISPMODE_OFF ((GXDispMode)0x00)
#define HW_IOREG 0x04000000
#define HW_REG_BASE HW_IOREG        // alias
#define REG_DISPCNT_OFFSET 0x000
#define REG_DISPCNT_ADDR (HW_REG_BASE + REG_DISPCNT_OFFSET)
#define reg_GX_DISPCNT (*( REGType32v *) REG_DISPCNT_ADDR)
#define REG_GX_DISPCNT_VRAM_MASK 0x000c0000
#define REG_GX_DISPCNT_MODE_SHIFT 16
#define REG_GX_DISPCNT_MODE_MASK 0x00030000
#define REG_GX_DISPCNT_BG02D3D_SHIFT 3
#define REG_GX_DISPCNT_BG02D3D_MASK 0x00000008
#define REG_GX_DISPCNT_BGMODE_SHIFT 0
#define REG_GX_DISPCNT_BGMODE_MASK 0x00000007

typedef enum {
    GX_BGMODE_0 = 0,
    GX_BGMODE_1 = 1,
    GX_BGMODE_2 = 2,
    GX_BGMODE_3 = 3,
    GX_BGMODE_4 = 4,
    GX_BGMODE_5 = 5,
    GX_BGMODE_6 = 6
} GXBGMode;
typedef enum {
    GX_BG0_AS_2D = 0,
    GX_BG0_AS_3D = 1
} GXBG0As;
typedef enum {
    GX_DISPMODE_GRAPHICS = 0x01,
    GX_DISPMODE_VRAM_A = 0x02,
    GX_DISPMODE_VRAM_B = 0x06,
    GX_DISPMODE_VRAM_C = 0x0a,
    GX_DISPMODE_VRAM_D = 0x0e,
    GX_DISPMODE_MMEM = 0x03
} GXDispMode;
extern u16 data_020446d0;
extern u16 data_020422b4;

/* GX_SetGraphicsMode -- NitroSDK gx.c: GX_SetGraphicsMode. */
void GX_SetGraphicsMode (GXDispMode dispMode, GXBGMode bgMode, GXBG0As bg0_2d3d)
{
	u32 cnt = reg_GX_DISPCNT;

	data_020446d0 = (u16)dispMode;
	if (!data_020422b4) {
		dispMode = GX_DISPMODE_OFF;
	}

	cnt &= ~(REG_GX_DISPCNT_BGMODE_MASK |
	         REG_GX_DISPCNT_BG02D3D_MASK | REG_GX_DISPCNT_MODE_MASK | REG_GX_DISPCNT_VRAM_MASK);

	reg_GX_DISPCNT = (u32)(cnt |
	                       (dispMode << REG_GX_DISPCNT_MODE_SHIFT) |
	                       (bgMode << REG_GX_DISPCNT_BGMODE_SHIFT) | (bg0_2d3d <<
	                                                                  REG_GX_DISPCNT_BG02D3D_SHIFT));

	if (data_020446d0 == GX_DISPMODE_OFF) {
		data_020422b4 = FALSE;
	}
}
