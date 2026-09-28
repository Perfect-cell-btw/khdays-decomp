/*
 * Ov002_LeavePanelForMap - hand the screen back to the map and park the panel
 * in state 10.
 *
 * The scroll tween finishing retunes the ambient emitter, and that runs before
 * the screen gate is even consulted. Past the gate, the flag at +0x40 says the
 * panel had taken the screen over: the map snapshot is pushed back, the entry
 * selection is dropped, and both BG screens are wiped a full 0x800 bytes.
 *
 * The help layer is restored unless the mode bit is set and the context is
 * already running BG2 in 256 colours, which is the case that owns it.
 *
 * ARM.
 */

typedef unsigned char u8;

typedef struct {
    char pad0000[0x40];
    int bOwnsScreen;                    /* +0x040 */
    char pad0044[0x18];
    int bBg2Is256Colour;                /* +0x05c */
    char pad0060[0xcc];
    unsigned int dwScrollTweenFlags;    /* +0x12c Tween.dwFlags, bit 2 = finished */
    char pad0130[0x5c];
    int nPanelState;                    /* +0x18c */
} Ov002PanelContext;

extern Ov002PanelContext *data_ov002_0207f614;
extern u8 data_0204c240;

extern void *G2_GetBG1ScrPtr(void);
extern void *G2_GetBG3ScrPtr(void);
extern void INITi_CpuClear32_0x01ff86fc(unsigned int nValue, void *pDst,
                                        unsigned int nSize);
extern int Ov002_World_IsFlagBit2Set(void);
extern void Ov002_World_SetFadeLevel(int nId);
extern void Ov002_PushMapSnapshot(int a);
extern void Ov002_SelectEntryByKey(int nKey);
extern void Ov002_RetuneAmbientEmitter(void);
extern void Ov002_SceneReopenPanel(int a);

void Ov002_LeavePanelForMap(void)
{
    Ov002PanelContext *ctx;

    ctx = data_ov002_0207f614;
    if (((unsigned int)((int)ctx->dwScrollTweenFlags << 0x1d) >> 0x1f) != 0) {
        Ov002_RetuneAmbientEmitter();
    }
    if (Ov002_World_IsFlagBit2Set() == 0) {
        return;
    }

    if (ctx->bOwnsScreen != 0) {
        Ov002_PushMapSnapshot(0);
        Ov002_SelectEntryByKey(-1);
        INITi_CpuClear32_0x01ff86fc(0, G2_GetBG1ScrPtr(), 0x800);
        INITi_CpuClear32_0x01ff86fc(0, G2_GetBG3ScrPtr(), 0x800);
    }
    if ((data_0204c240 & 4) == 0 || ctx->bBg2Is256Colour == 0) {
        Ov002_World_SetFadeLevel(0xd);
    }
    Ov002_SceneReopenPanel(0);
    ctx->nPanelState = 10;
}
