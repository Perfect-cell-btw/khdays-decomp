/* Ov025_BuildMissionListRows -- Ov008_BuildMissionListRows: build the mission list's
 * row surfaces.  Clears the 32 x 32 grid of slot 0x1a and takes its handle;
 * for each of the six rows builds the name surface at x = 2 + 4 * i, y = 6,
 * the info surface at x = 4 * i, y = 6, and the extra surface at x = 4 * i
 * with y = 0x19 while the entry gate (+0x40) is clear or 0x16 while it is set
 * (both tests are kept, as the ROM re-reads the gate).  Rows beyond the
 * mission count get their three surfaces refreshed instead; then the scroll
 * geometry is initialised, row 0 selected with cue 2, and unless the list is
 * dirty (+0x48) the rows are refilled.
 * NOTE: the row loop is written with plain indexing (&aRow[i], i * 4 + 2); mwcc
 * strength-reduces it into the ROM's six induction registers itself -- explicit
 * walking pointers / counters colour them differently.
 */
#include "nitro/types.h"

#define ROW_COUNT 6
#define GRID_SLOT 0x1a

typedef struct TileSurface {
    u8 pad[0x3c];
} TileSurface;

typedef struct Ov008MissionList {
    u8  pad_000[0x40];
    int bEntryGate;           /* 0x040 */
    u8  pad_044[4];
    int bDirty;               /* 0x048 */
    u8  pad_04c[0x84 - 0x4c];
    TileSurface aRowNameSurface[ROW_COUNT];  /* 0x084 */
    TileSurface aRowInfoSurface[ROW_COUNT];  /* 0x1ec */
    TileSurface aRowExtraSurface[ROW_COUNT]; /* 0x354 */
} Ov008MissionList;

extern void Ov025_ClearGridRows(int nSlot, int nX, int nY, int nW, int nH); /* Ov008_ClearGridRows */
extern int  Ov025_LookupEntry(int nSlot);                               /* Ov008_ResetEntry: slot handle */
extern void Draw_ScaledValue(TileSurface *pSurface, int hLayer, int nX, int nY, int nPalette); /* Draw_ScaledValue */
extern u16  Ov025_GetCurrentListId(void);                                    /* mission entry count */
extern void Obj_InvokeInnerVtable4(TileSurface *pSurface);                         /* Obj_InvokeInnerVtable4 */
extern void Ov025_MissionList_SetupScrollBar(Ov008MissionList *pList);                 /* Ov008_InitMissionListLayout */
extern void Ov025_MissionListSelectRow(Ov008MissionList *pList, int nRow, int nSound); /* Ov008_MissionListSelectRow */
extern void Ov025_RefillListRows(Ov008MissionList *pList);                 /* Ov008_RefillListRows */

void Ov025_BuildMissionListRows(Ov008MissionList *pList)
{
    int hLayer;
    int i;

    Ov025_ClearGridRows(GRID_SLOT, 0, 0, 0x20, 0x20);
    hLayer = Ov025_LookupEntry(GRID_SLOT);
    for (i = 0; i < ROW_COUNT; i++) {
        Draw_ScaledValue(&pList->aRowNameSurface[i], hLayer, i * 4 + 2, 6, 0);
        Draw_ScaledValue(&pList->aRowInfoSurface[i], hLayer, i * 4, 6, 0);
        if (pList->bEntryGate == 0) {
            Draw_ScaledValue(&pList->aRowExtraSurface[i], hLayer, i * 4, 0x19, 0);
        }
        if (pList->bEntryGate != 0) {
            Draw_ScaledValue(&pList->aRowExtraSurface[i], hLayer, i * 4, 0x16, 0);
        }
    }
    for (i = Ov025_GetCurrentListId(); i < ROW_COUNT; i++) {
        Obj_InvokeInnerVtable4(&pList->aRowNameSurface[i]);
        Obj_InvokeInnerVtable4(&pList->aRowInfoSurface[i]);
        Obj_InvokeInnerVtable4(&pList->aRowExtraSurface[i]);
    }
    Ov025_MissionList_SetupScrollBar(pList);
    Ov025_MissionListSelectRow(pList, 0, 2);
    if (pList->bDirty == 0) {
        Ov025_RefillListRows(pList);
    }
}
