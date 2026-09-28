/* Ov008_HideMissionMenuWidgets -- Ov008_HideMissionMenuWidgets: hide the mission
 * menu's widgets in context block 4a80: pushes widget 2's sub-item set on and
 * 0x16's off, hides widget 1 (twice, as the ROM does), the scroll bar widgets
 * 2..0x13, the row widgets 0x16..0x20 and the five extras 0x34..0x38.
 * The menu pointer is the parameter its only caller (Ov008_MissionMenuInitStep)
 * passes; it is not read.
 */
#define WIDGET_LIST      2
#define WIDGET_ROWS      0x16
#define WIDGET_BAR_LAST  0x13
#define WIDGET_ROW_LAST  0x20

typedef struct Ov008MissionMenu Ov008MissionMenu;  /* the caller's menu, not read here */

extern int  Ov008_GetCtxBlock4a80(void);                                   /* Ov008_GetCtxBlock4a80 */
extern void *Ov008_FindEntryById(int nCtx, int nId);                     /* FindEntryById */
extern void Ov008_PushSubitemSet(int nCtx, void *pEntry, int nValue);     /* Ov008_PushSubitemSet */
extern void Ov008_SetEntrySlotsVisible(int nCtx, void *pEntry, int bVisible);   /* SetEntrySlotsVisible */

void Ov008_HideMissionMenuWidgets(Ov008MissionMenu *pMenu)
{
    int nCtx;
    int i;

    nCtx = Ov008_GetCtxBlock4a80();
    Ov008_PushSubitemSet(nCtx, Ov008_FindEntryById(nCtx, WIDGET_LIST), 1);
    Ov008_PushSubitemSet(nCtx, Ov008_FindEntryById(nCtx, WIDGET_ROWS), 0);
    Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, 1), 0);
    Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, 1), 0);
    for (i = WIDGET_LIST; i <= WIDGET_BAR_LAST; i++) {
        Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, i), 0);
    }
    for (i = WIDGET_ROWS; i <= WIDGET_ROW_LAST; i++) {
        Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, i), 0);
    }
    Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, 0x34), 0);
    Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, 0x35), 0);
    Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, 0x36), 0);
    Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, 0x37), 0);
    Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, 0x38), 0);
}
