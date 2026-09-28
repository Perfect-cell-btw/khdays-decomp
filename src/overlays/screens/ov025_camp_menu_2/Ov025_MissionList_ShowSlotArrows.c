/* Ov025_MissionList_ShowSlotArrows -- Ov025_MissionList_ShowSlotArrows: count the slots of the twelve that
 * have missions (select each with Ov025_SelectMissionSlot 0208dc8c and read the entry count
 * 0208dc74), reselect the cursor's slot (+0x54) and, with two or more, show entries 4 / 5 of the
 * 4a7c block (02084a7c) and 0x47 / 0x48 of the 4a80 block (02084a8c): the slot arrows
 * (FindEntryById 0208843c / SetEntrySlotsVisible 0208884c). */
#include "nitro/types.h"

typedef struct Ov008MissionList {
    int  nSelected;           /* 0x000 */
    int  nPrevSelected;       /* 0x004 */
    int  nCursorRow;          /* 0x008 */
    int  nScroll;             /* 0x00c: in pixels, 32 a row */
    u8   pad_010[0x54 - 0x10];
    u8   nCursorSlot;         /* 0x054: the accepted slot the cursor is on */
} Ov008MissionList;

typedef struct UiLayoutPos {
    int  x;                   /* 0x00 */
    int  y;                   /* 0x04 */
} UiLayoutPos;

extern void  Ov025_EncodeCursorAction(int nSlot);                        /* Ov025_SelectMissionSlot */
extern u16   Ov025_GetCurrentListId(void);                             /* Ov025_MissionSlotEntryCount */
extern int   Ov025_GetContext(void);                             /* Ov008_GetCtxBlock4a7c */
extern int   Ov025_GetBlock4a80(void);                             /* Ov008_GetCtxBlock4a80 */
extern void *Ov025_FindEntryById(int nCtx, int nId);                /* FindEntryById */
extern void  Ov025_SetEntrySlotsVisible(int nCtx, void *pEntry, int bVisible); /* SetEntrySlotsVisible */

void Ov025_MissionList_ShowSlotArrows(Ov008MissionList *pList)
{
    int nAccepted;
    int i;
    int nCtx;

    nAccepted = 0;
    for (i = 0; i < 12; i++) {
        Ov025_EncodeCursorAction((u16)i);
        if (Ov025_GetCurrentListId() != 0) {
            nAccepted++;
        }
    }
    Ov025_EncodeCursorAction(pList->nCursorSlot);
    if (nAccepted < 2) {
        return;
    }
    nCtx = Ov025_GetContext();
    Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, 4), 1);
    Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, 5), 1);
    nCtx = Ov025_GetBlock4a80();
    Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, 0x47), 1);
    Ov025_SetEntrySlotsVisible(nCtx, Ov025_FindEntryById(nCtx, 0x48), 1);
}
