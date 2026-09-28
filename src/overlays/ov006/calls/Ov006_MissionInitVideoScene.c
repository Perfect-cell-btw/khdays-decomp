typedef unsigned short u16;
typedef unsigned int u32;

extern void Gfx_Reset2DEngines(void);
extern void Res_TearDownBlock(void);
extern int Game_PollSceneAlive(void);
extern void Ov105_RunScriptedStepState3(void);
extern void Ov105_WH_Finalize(void);
extern u16 *GXx_SetMasterBrightness_(u16 *reg, int brightness);
extern int Ov006_Link_GetField4F0(void);
extern u16 Ov105_GetState(void);
extern u16 Ov105_GetStatusLow(void);
extern void func_0202362c(int value);
extern void func_02003948(u32 value);

void *Ov006_MissionInitVideoScene(void) {
    u32 packed;

    *(volatile u16 *)0x05000000 = 0;
    *(volatile u16 *)0x05000400 = 0;
    *(volatile u32 *)0x04000000 &= ~0x1f00;
    *(volatile u32 *)0x04001000 &= ~0x1f00;

    Gfx_Reset2DEngines();
    Res_TearDownBlock();

    if (Game_PollSceneAlive() != 0) {
        int waiting = 1;
        int stopped = 0;

        do {
            switch (Game_PollSceneAlive()) {
            case 1:
                Ov105_RunScriptedStepState3();
                break;
            case 0:
                waiting = stopped;
                break;
            case 3:
                break;
            default:
                Ov105_WH_Finalize();
                break;
            }
        } while (waiting != 0);
    }

    GXx_SetMasterBrightness_((u16 *)0x0400006c, 0x10);
    GXx_SetMasterBrightness_((u16 *)0x0400106c, 0x10);

    if (Ov006_Link_GetField4F0() != 0) {
        packed = (u32)-1;
    } else {
        u16 high = Ov105_GetState();
        u16 low = Ov105_GetStatusLow();

        packed = ((u32)high << 16) | low | 0x80000000;
    }

    func_0202362c(0);
    func_02003948(packed);
    return 0;
}
