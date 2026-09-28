/* Ov025_PlaceTutorialSurfaces -- Ov008_PlaceTutorialSurfaces: clear the tutorial layer
 * (slot 0x1b, 32 x 32 rows) and place page B's tutorial surfaces on it: the
 * first three at (0,2), (0,0x19), (3,2); then for tutorial kind 0x11 the sixth,
 * seventh and eighth at (8,0x12), (0xd,0x12), (0x13,0x12), otherwise the fifth
 * at (0x14,2); all with palette 0xf.
 */
typedef unsigned char u8;

#define SLOT_TUTORIAL 0x1b
#define PALETTE_TUTORIAL 0xf
#define KIND_THREE_PANEL 0x11

typedef struct TileSurface {
    u8 pad[0x3c];
} TileSurface;

typedef struct Ov008PageB {
    int nKind;                /* 0x000 */
    u8  pad_004[0x38 - 0x4];
    TileSurface aSurface[7];  /* 0x038 */
} Ov008PageB;

extern Ov008PageB *Ov025_GetPageB(void);                              /* Ov008_GetPageB */
extern void Ov025_ClearGridRows(int nSlot, int nX, int nY, int nW, int nH); /* Ov008_ClearGridRows */
extern int Ov025_LookupEntry(int nSlot);                                 /* Ov008_ResetEntry */
extern void Draw_ScaledValue(TileSurface *pSurface, int hLayer, int nX, int nY, int nPalette); /* Draw_ScaledValue */

void Ov025_PlaceTutorialSurfaces(void)
{
    Ov008PageB *pPage = Ov025_GetPageB();
    int hLayer;

    Ov025_ClearGridRows(SLOT_TUTORIAL, 0, 0, 0x20, 0x20);
    hLayer = Ov025_LookupEntry(SLOT_TUTORIAL);
    Draw_ScaledValue(&pPage->aSurface[0], hLayer, 0, 2, PALETTE_TUTORIAL);
    Draw_ScaledValue(&pPage->aSurface[1], hLayer, 0, 0x19, PALETTE_TUTORIAL);
    Draw_ScaledValue(&pPage->aSurface[2], hLayer, 3, 2, PALETTE_TUTORIAL);
    if (pPage->nKind == KIND_THREE_PANEL) {
        Draw_ScaledValue(&pPage->aSurface[4], hLayer, 8, 0x12, PALETTE_TUTORIAL);
        Draw_ScaledValue(&pPage->aSurface[5], hLayer, 0xd, 0x12, PALETTE_TUTORIAL);
        Draw_ScaledValue(&pPage->aSurface[6], hLayer, 0x13, 0x12, PALETTE_TUTORIAL);
    } else {
        Draw_ScaledValue(&pPage->aSurface[3], hLayer, 0x14, 2, PALETTE_TUTORIAL);
    }
}
