/* Ov025_HideGridMenu -- Ov008_HideGridMenu: hide the grid menu's widgets.
 * Clears the 64 x 32 grids of slots 9 and 10, hides widgets 0x49 and 0x28,
 * clears the eight row header cells' active words (+0x16e0, stride 0x28),
 * hides the seven widgets of data_ov025_020b3d10 (41..47, copied to the
 * stack), the segment widgets 0xd..0x1a, 0x37..0x38 and 0x50..0x5f.
 */

#include "nitro/types.h"

#define ROW_COUNT   8
#define EXTRA_COUNT 7

typedef struct Ov008GridDisplayCell {
    int isActive;             /* 0x00 */
    u8  pad_04[0x28 - 4];
} Ov008GridDisplayCell;

typedef struct Ov008MenuContext {
    u8  pad_0000[0x16e0];
    Ov008GridDisplayCell rowHeaderCells[ROW_COUNT]; /* 0x16e0 */
} Ov008MenuContext;

typedef struct Ov008WidgetIdTable {
    int aId[EXTRA_COUNT];
} Ov008WidgetIdTable;

extern const Ov008WidgetIdTable data_ov025_020b3d10;
extern int  Ov025_GetCtxBlock9500(void);                                   /* Ov008_GetCtxBlock9500 */
extern int  Ov025_GetContext(void);                                   /* Ov008_GetContext */
extern void Ov025_ClearGridRows(int nSlot, int nX, int nY, int nW, int nH); /* Ov008_ClearGridRows */
extern void *Ov025_FindEntryById(int nCtx, int nId);                     /* FindEntryById */
extern void Ov025_SetEntrySlotsVisible(int nCtx, void *pEntry, int bVisible);   /* SetEntrySlotsVisible */

void Ov025_HideGridMenu(Ov008MenuContext *pCtx)
{
    Ov008WidgetIdTable ids;
    int nCtx;
    int i;

    ids = data_ov025_020b3d10;
    Ov025_GetCtxBlock9500();
    nCtx = Ov025_GetContext();
    Ov025_ClearGridRows(9, 0, 0, 0x40, 0x20);
    Ov025_ClearGridRows(10, 0, 0, 0x40, 0x20);
    Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, 0x49), 0);
    Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, 0x28), 0);
    for (i = 0; i < ROW_COUNT; i++) {
        pCtx->rowHeaderCells[i].isActive = 0;
    }
    for (i = 0; i < EXTRA_COUNT; i++) {
        Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, ids.aId[i]), 0);
    }
    for (i = 0xd; i <= 0x1a; i++) {
        Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, i), 0);
    }
    for (i = 0x37; i <= 0x38; i++) {
        Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, i), 0);
    }
    for (i = 0x50; i <= 0x5f; i++) {
        Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, i), 0);
    }
}
