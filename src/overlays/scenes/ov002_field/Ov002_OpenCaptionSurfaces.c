/*
 * Ov002_OpenCaptionSurfaces - open the caption screen's surfaces and start the
 * loads that fill them.
 *
 * Each surface's configuration takes the tile block, the screen block and the
 * palette the allocator hands out, and is then opened over its own slot of the
 * scene. The wide layout adds a third surface, marks its own ready flag, hands
 * the current message to the animation block unless it is the placeholder, and
 * kicks the tally load.
 *
 * The main caption surface is opened last, cleared to blank, and its own load
 * is kicked; both of its ready flags go up on the way out.
 *
 * THUMB.
 */

typedef struct {
    char pad000[0x1c];
    int nCharBase;
    char pad020[4];
    int nScreenBase;
    char pad028[4];
    int nPalette;
    char pad030[0x34];
    int nPriority;
    char pad068[4];
    int nCharBase2;
    char pad070[4];
    int nScreenBase2;
    char pad078[4];
    int nPalette2;
} Ov002SurfaceCfg;

typedef struct {
    char pad000[0x14];
    int nCharBase;
    char pad018[4];
    int nScreenBase;
    char pad020[4];
    int nPalette;
} Ov002TallyCfg;

typedef struct {
    char pad000[0x8c];
    int bReadyA;
    int bReadyB;
    int bReadyC;
    char pad098[0x28];
    char surfTop[0x3c];
    char surfMain[0x3c];
    char surfTally[0x88];
    char animBlock[0x14];
} Ov002TextScene;

extern int data_ov002_0207f62c;
extern Ov002SurfaceCfg data_ov002_0207ebf4;
extern Ov002TallyCfg data_ov002_0207ec74;
extern const char data_ov002_0207ec00[];
extern const char data_ov002_0207ec78[];
extern const char data_ov002_0207ec50[];
extern const char gOv002UiBtlBmLoBg007Path[];
extern const char gOv002UiBtlBmLoBg003Path[];

extern void TileSurface_InitAndUpload4bpp(void *pSurface, const void *pConfig);
extern void InvokeSubObjectMethod(void *pSurface, int nValue);
extern int GameState_GetField(int a, int b);

extern int Ov002_ConstReturn0x3af(void);
extern int Ov002_GetItemResource(int nId);
extern int Ov002_Hud_GetBlock30(void);
extern int Ov002_GetPanelField0058(void);
extern void Ov002_AppendEntry(const char *pName, void *pDone, int nFlags);
extern void Ov002_DrawLoadedTally(void *pNode);
extern void Ov002_DrawLoadedPortrait(void *pNode);
extern void Ov069_TallyMissionRecords(void *pAnim);

void Ov002_OpenCaptionSurfaces(void)
{
    Ov002TextScene *s;

    s = *(Ov002TextScene **)((char *)&data_ov002_0207f62c + 4);

    data_ov002_0207ebf4.nCharBase = Ov002_ConstReturn0x3af();
    data_ov002_0207ebf4.nScreenBase = Ov002_GetItemResource(0x1a);
    data_ov002_0207ebf4.nPalette = Ov002_Hud_GetBlock30();
    TileSurface_InitAndUpload4bpp(s->surfTop, data_ov002_0207ec00);

    data_ov002_0207ebf4.nCharBase2 = Ov002_ConstReturn0x3af() + 0x1e;
    data_ov002_0207ebf4.nScreenBase2 = Ov002_GetItemResource(0x1a);
    data_ov002_0207ebf4.nPalette2 = Ov002_Hud_GetBlock30();

    if (Ov002_GetPanelField0058() != 0) {
        data_ov002_0207ebf4.nPriority = 0xa;
        data_ov002_0207ec74.nCharBase = Ov002_ConstReturn0x3af() + 0x32;
        data_ov002_0207ec74.nScreenBase = Ov002_GetItemResource(0x1a);
        data_ov002_0207ec74.nPalette = Ov002_Hud_GetBlock30();
        TileSurface_InitAndUpload4bpp(s->surfTally, data_ov002_0207ec78);
        s->bReadyC = 1;
        if (GameState_GetField(0, 9) != 0x165) {
            Ov069_TallyMissionRecords(s->animBlock);
        }
        Ov002_AppendEntry(gOv002UiBtlBmLoBg007Path, Ov002_DrawLoadedTally, 0);
    }

    TileSurface_InitAndUpload4bpp(s->surfMain, data_ov002_0207ec50);
    InvokeSubObjectMethod(s->surfMain, 2);
    Ov002_AppendEntry(gOv002UiBtlBmLoBg003Path, Ov002_DrawLoadedPortrait, 0);
    s->bReadyA = 1;
    s->bReadyB = 1;
}
