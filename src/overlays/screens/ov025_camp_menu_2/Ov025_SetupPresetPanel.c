/* Ov025_SetupPresetPanel -- Ov008_SetupPresetPanel: display setup for the three
 * preset rows and the page indicator of the grid menu.  Each preset surface
 * (+0x160, 0x3c apart) is built on layer hLayer at x = 8 + 3 * i, bound to the
 * row's target (+0x29c, 0x10 apart), and gets its var record (+0x28c, index
 * 0x10 + i) drawn twice (0x39 / 0x38, colour 0xf3 when the preset is
 * unlocked -- flag 0x3c67 + i, or always with bAll -- else 0xf5).  With bAll
 * entries 0x59..0x5b and 0x57 are enabled and entry 0x59 re-linked, selecting
 * page target 2; otherwise entries 0x5d..0x5f are shown with their subitem set
 * pushed from flag 0x3c0a + id, entry 0x58 enabled and entry 0x5d + preset
 * (+0x20) re-linked, selecting page target 0.  The page surface (+0x214) is
 * built at x = 4 and bound to that target (+0x2c8).
 * Codegen: the surface pointer and x are indexed from i at every use (mwcc
 * strength-reduces them into r7 / r6 itself; explicit walking locals colour
 * the other way round).
 */

#include "nitro/types.h"

#define PRESET_COUNT      3
#define FLAG_PRESET_BASE  0x3c67
#define FLAG_ENTRY_BASE   0x3c0a
#define COLOUR_UNLOCKED   0xf3
#define COLOUR_LOCKED     0xf5
#define TEXT_FLAGS        0x412

typedef struct TileSurface {
    u8 pad_00[0x3c];
} TileSurface;

typedef struct Ov008PresetRow {
    int hTarget;              /* 0x00 */
    u8  pad_04[0xc];
} Ov008PresetRow;

typedef struct Ov008MenuContext {
    u8  pad_0000[0x20];
    int nPreset;              /* 0x020 */
    u8  pad_0024[0x160 - 0x24];
    TileSurface aPresetSurface[PRESET_COUNT]; /* 0x160 */
    TileSurface pageSurface;  /* 0x214 */
    u8  pad_0250[0x28c - 0x250];
    u8  varRecords[0x10];     /* 0x28c */
    Ov008PresetRow aPresetRow[PRESET_COUNT]; /* 0x29c */
    u8  pad_02cc[0x2c8 - 0x2cc + 4];
} Ov008MenuContext;

extern const u8 data_ov008_020635c4[];
extern void  Draw_ScaledValue(TileSurface *pSurface, int hLayer, int nX, int nY, int nPalette); /* Draw_ScaledValue */
extern void  TileSurface_SetCurrentItem(TileSurface *pSurface, int nTarget, int nUpdate);          /* TileSurface_SetCurrentItem */
extern int   GameState_IsFlagSet(int nFlag);                                                 /* GameState_IsFlagSet */
extern void *Ov025_GetVarRecordByIndex(void *pRecords, int nIndex);                          /* GetVarRecordByIndex */
extern void  Obj_InvokeInnerVtable4(TileSurface *pSurface);                                     /* Obj_InvokeInnerVtable4 */
extern void  Text_DrawDirectional_2(TileSurface *pSurface, int nX, int nY, int nColour, u32 nFlags, void *pRecord); /* Text_DrawDirectional */
extern void  EnqueueObjGfxCommand(TileSurface *pSurface);                                     /* EnqueueObjGfxCommand */
extern void  Ov025_ResolveEntryAndConfigure(void *pMenu, int nId, int bEnable);                   /* Ov008_ResolveEntryAndConfigure */
extern void *Ov025_FindEntryById(void *pMenu, int nId);                                /* FindEntryById */
extern void  Ov025_SwapParamOverrides(void *pMenu, void *pEntry);                           /* Ov008_SwapParamOverrides */
extern void  Ov025_ConfigureSlotWithHeight(void *pEntry);                                        /* Ov008_SetTag3RowPos */
extern void  Ov025_SetEntrySlotsVisible(void *pMenu, void *pEntry, int bVisible);             /* SetEntrySlotsVisible */
extern void  Ov025_PushSubitemSet(void *pMenu, void *pEntry, int nValue);               /* Ov008_PushSubitemSet */

void Ov025_SetupPresetPanel(Ov008MenuContext *pCtx, void *pMenu, int hLayer, int bAll)
{
    int i;
    int bUnlocked;
    void *pRecord;
    int nColour;
    void *pEntry;
    int nTarget;

    for (i = 0; i < PRESET_COUNT; i++) {
        Draw_ScaledValue(&pCtx->aPresetSurface[i], hLayer, 8 + i * 3, 0xf, 0);
        TileSurface_SetCurrentItem(&pCtx->aPresetSurface[i], pCtx->aPresetRow[i].hTarget, 1);
        if (bAll != 0) {
            bUnlocked = 1;
        } else {
            bUnlocked = GameState_IsFlagSet(FLAG_PRESET_BASE + i);
        }
        pRecord = Ov025_GetVarRecordByIndex(pCtx->varRecords, i + 0x10);
        if (bUnlocked != 0) {
            nColour = COLOUR_UNLOCKED;
        } else {
            nColour = COLOUR_LOCKED;
        }
        Obj_InvokeInnerVtable4(&pCtx->aPresetSurface[i]);
        Text_DrawDirectional_2(&pCtx->aPresetSurface[i], 0x39, 7, nColour - 1, TEXT_FLAGS, pRecord);
        Text_DrawDirectional_2(&pCtx->aPresetSurface[i], 0x38, 6, nColour, TEXT_FLAGS, pRecord);
        EnqueueObjGfxCommand(&pCtx->aPresetSurface[i]);
    }
    if (bAll != 0) {
        for (i = 0x59; i <= 0x5b; i++) {
            Ov025_ResolveEntryAndConfigure(pMenu, i, 1);
        }
        Ov025_ResolveEntryAndConfigure(pMenu, 0x57, 1);
        nTarget = 2;
        Ov025_SwapParamOverrides(pMenu, Ov025_FindEntryById(pMenu, 0x59));
        Ov025_ConfigureSlotWithHeight(Ov025_FindEntryById(pMenu, 0x59));
    } else {
        for (i = 0x5d; i <= 0x5f; i++) {
            pEntry = Ov025_FindEntryById(pMenu, i);
            Ov025_SetEntrySlotsVisible(pMenu, pEntry, 1);
            Ov025_PushSubitemSet(pMenu, pEntry, GameState_IsFlagSet(FLAG_ENTRY_BASE + i) == 0);
        }
        Ov025_ResolveEntryAndConfigure(pMenu, 0x58, 1);
        nTarget = 0;
        Ov025_SwapParamOverrides(pMenu, Ov025_FindEntryById(pMenu, pCtx->nPreset + 0x5d));
        Ov025_ConfigureSlotWithHeight(Ov025_FindEntryById(pMenu, pCtx->nPreset + 0x5d));
    }
    Draw_ScaledValue(&pCtx->pageSurface, hLayer, 4, 0xf, 0);
    TileSurface_SetCurrentItem(&pCtx->pageSurface, *(int *)((u8 *)pCtx + 0x2c8 + nTarget * 4) /* page targets: the screen's target table is laid out per screen */, 1);
}
