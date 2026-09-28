/* Ov008_UpdateMissionListArrows -- Ov008_UpdateMissionListArrows: show or hide the
 * mission list's page arrows.  Counts how many of the twelve cursor picks
 * (0205b720 with 0..11) leave a non-empty entry count, restores the pick to
 * the list's cursor slot (+0x54), and wants the arrows shown when at least
 * two pages have entries and the list state (0205b7b4) is not 7.  Widgets 4
 * and 5 of the context and 0x47 / 0x48 of block 4a80 are then set visible
 * only when their current visibility (field 0x84 bit 1) differs.
 */
#include "nitro/types.h"

#define PICK_COUNT     12
#define LIST_STATE_END 7

typedef struct Ov008MissionList {
    u8  pad_00[0x54];
    u8  nCursorSlot;          /* 0x54 */
} Ov008MissionList;

extern void Ov008_EncodeCursorAction(int nSlot);                              /* cursor pick */
extern u16  Ov008_GetCurrentListId(void);                                   /* mission entry count */
extern int  Ov008_GetMenuField1408(void);                                   /* list state */
extern int  Ov008_GetContext(void);                                   /* Ov008_GetContext */
extern int  Ov008_GetCtxBlock4a80(void);                                   /* Ov008_GetCtxBlock4a80 */
extern void *Ov008_FindEntryById(int nCtx, int nId);                     /* FindEntryById */
extern int  Ov008_GetField84Bit1(int nCtx, void *pEntry);                 /* ov008_GetField84Bit1: visible */
extern void Ov008_SetEntrySlotsVisible(int nCtx, void *pEntry, int bVisible);   /* SetEntrySlotsVisible */

void Ov008_UpdateMissionListArrows(Ov008MissionList *pList)
{
    int bShow;
    int nPages;
    int i;
    int nCtx;
    int bVisibleA;
    int bVisibleB;

    nPages = 0;
    bShow = 1;
    for (i = 0; i < PICK_COUNT; i++) {
        Ov008_EncodeCursorAction((u16)i);
        if (Ov008_GetCurrentListId() != 0) {
            nPages++;
        }
    }
    Ov008_EncodeCursorAction(pList->nCursorSlot);
    if (nPages < 2) {
        bShow = 0;
    }
    if (Ov008_GetMenuField1408() == LIST_STATE_END) {
        bShow = 0;
    }
    nCtx = Ov008_GetContext();
    bVisibleA = Ov008_GetField84Bit1(nCtx, Ov008_FindEntryById(nCtx, 4)) != 0;
    bVisibleB = Ov008_GetField84Bit1(nCtx, Ov008_FindEntryById(nCtx, 5)) != 0;
    if (bShow != bVisibleA) {
        Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, 4), bShow);
    }
    if (bShow != bVisibleB) {
        Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, 5), bShow);
    }
    nCtx = Ov008_GetCtxBlock4a80();
    bVisibleA = Ov008_GetField84Bit1(nCtx, Ov008_FindEntryById(nCtx, 0x47)) != 0;
    bVisibleB = Ov008_GetField84Bit1(nCtx, Ov008_FindEntryById(nCtx, 0x48)) != 0;
    if (bShow != bVisibleA) {
        Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, 0x47), bShow);
    }
    if (bShow != bVisibleB) {
        Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, 0x48), bShow);
    }
}
