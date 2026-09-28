/* Ov008_InitMissionListLayout -- Ov008_InitMissionListLayout: reset the mission
 * list's scroll geometry from the entry count (32 px per row): scroll and
 * track position 0, view height 0xa0, top 0x10, scroll scale = total height
 * minus the view (clamped at 0), knob length = view height, or view^2 / total
 * when the list is taller than the view, at least 0x20, and track max = view
 * height minus the knob.  Then the knob segment widgets 4..0x13 are shown
 * while (knob - 0x10) exceeds 8 * (i - 3) and hidden otherwise, the end caps
 * 2 and 3 are shown, widgets 2..0x13 get their two slots released, and the
 * rows and scroll arrows are laid out.
 */

#include "nitro/types.h"

#define ROW_HEIGHT   32
#define VIEW_HEIGHT  0xa0
#define VIEW_TOP     0x10
#define KNOB_MIN     0x20
#define KNOB_PAD     0x10
#define SEGMENT_STEP 8
#define WIDGET_CAP_A 2
#define WIDGET_CAP_B 3
#define WIDGET_FIRST 4
#define WIDGET_LAST  0x13

typedef struct Ov008MissionList {
    u8  pad_00[0xc];
    int nScroll;              /* 0x0c */
    u8  pad_10[4];
    int nTop;                 /* 0x14 */
    int nHeight;              /* 0x18 */
    int nScrollScale;         /* 0x1c */
    int nTrackPos;            /* 0x20 */
    int nKnobLength;          /* 0x24 */
    int nTrackMax;            /* 0x28 */
} Ov008MissionList;

extern u16  Ov008_GetCurrentListId(void);                                    /* mission entry count */
extern int  func_02020400(int nNum, int nDen);                            /* _s32_div_f */
extern int  Ov008_GetCtxBlock4a80(void);                                    /* Ov008_GetCtxBlock4a80 */
extern void *Ov008_FindEntryById(int nCtx, int nId);                      /* FindEntryById */
extern void Ov008_SetEntrySlotsVisible(int nCtx, void *pEntry, int bVisible);    /* SetEntrySlotsVisible */
extern void Ov008_ReleaseTwoSlots(int nCtx, void *pEntry);                  /* Ov008_ReleaseTwoSlots */
extern void Ov008_LayoutMenuRows(Ov008MissionList *pList);                 /* Ov008_LayoutMenuRows */
extern void Ov008_UpdateScrollArrows(Ov008MissionList *pList);                 /* Ov008_UpdateScrollArrows */

void Ov008_InitMissionListLayout(Ov008MissionList *pList)
{
    int nTotal;
    int nCtx;
    int i;

    nTotal = Ov008_GetCurrentListId() * ROW_HEIGHT;
    pList->nScroll = 0;
    pList->nTrackPos = 0;
    pList->nHeight = VIEW_HEIGHT;
    pList->nTop = VIEW_TOP;
    pList->nScrollScale = nTotal - pList->nHeight;
    if (pList->nScrollScale < 0) {
        pList->nScrollScale = 0;
    }
    pList->nKnobLength = pList->nHeight;
    if (nTotal > pList->nHeight) {
        pList->nKnobLength = func_02020400(pList->nHeight * pList->nHeight, nTotal);
    }
    if (pList->nKnobLength < KNOB_MIN) {
        pList->nKnobLength = KNOB_MIN;
    }
    pList->nTrackMax = pList->nHeight - pList->nKnobLength;
    nCtx = Ov008_GetCtxBlock4a80();
    for (i = WIDGET_FIRST; i <= WIDGET_LAST; i++) {
        if ((i - 3) * SEGMENT_STEP < pList->nKnobLength - KNOB_PAD) {
            Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, i), 1);
        } else {
            Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, i), 0);
        }
    }
    Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, WIDGET_CAP_A), 1);
    Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, WIDGET_CAP_B), 1);
    for (i = WIDGET_CAP_A; i <= WIDGET_LAST; i++) {
        Ov008_ReleaseTwoSlots(nCtx, Ov008_FindEntryById(nCtx, i));
    }
    Ov008_LayoutMenuRows(pList);
    Ov008_UpdateScrollArrows(pList);
}
