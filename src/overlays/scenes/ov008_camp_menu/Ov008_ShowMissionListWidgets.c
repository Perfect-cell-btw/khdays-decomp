/* Ov008_ShowMissionListWidgets -- Ov008_ShowMissionListWidgets: bring the mission
 * list's widgets in context block 4a80 up (the counterpart of
 * Ov008_HideMissionMenuWidgets): widget 1 is hidden while the list animates
 * (+0x68) and shown otherwise (both tests kept, as the ROM re-reads the flag),
 * the scroll bar widgets 2..0x13 are shown, the row widgets 0x16..0x20 hidden,
 * widget 2's sub-item set pushed off and 0x16's on, and the extras 0x33 and
 * 0x35..0x38 hidden.
 */

#include "nitro/types.h"

#define WIDGET_LIST      2
#define WIDGET_ROWS      0x16
#define WIDGET_BAR_LAST  0x13
#define WIDGET_ROW_LAST  0x20

typedef struct Ov008MissionList {
    u8  pad_00[0x68];
    int bAnimating;           /* 0x68 */
} Ov008MissionList;

extern int  Ov008_GetCtxBlock4a80(void);                                   /* Ov008_GetCtxBlock4a80 */
extern void *Ov008_FindEntryById(int nCtx, int nId);                     /* FindEntryById */
extern void Ov008_SetEntrySlotsVisible(int nCtx, void *pEntry, int bVisible);   /* SetEntrySlotsVisible */
extern void Ov008_PushSubitemSet(int nCtx, void *pEntry, int nValue);     /* Ov008_PushSubitemSet */

void Ov008_ShowMissionListWidgets(Ov008MissionList *pList)
{
    int nCtx;
    int i;

    nCtx = Ov008_GetCtxBlock4a80();
    if (pList->bAnimating != 0) {
        Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, 1), 0);
    }
    if (pList->bAnimating == 0) {
        Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, 1), 1);
    }
    for (i = WIDGET_LIST; i <= WIDGET_BAR_LAST; i++) {
        Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, i), 1);
    }
    for (i = WIDGET_ROWS; i <= WIDGET_ROW_LAST; i++) {
        Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, i), 0);
    }
    Ov008_PushSubitemSet(nCtx, Ov008_FindEntryById(nCtx, WIDGET_LIST), 0);
    Ov008_PushSubitemSet(nCtx, Ov008_FindEntryById(nCtx, WIDGET_ROWS), 1);
    Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, 0x33), 0);
    Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, 0x35), 0);
    Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, 0x36), 0);
    Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, 0x37), 0);
    Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, 0x38), 0);
}
