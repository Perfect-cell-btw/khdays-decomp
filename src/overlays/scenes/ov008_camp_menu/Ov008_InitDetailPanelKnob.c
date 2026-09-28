/* Ov008_InitDetailPanelKnob -- Ov008_InitDetailPanelKnob: size the detail panel's
 * scroll knob for nRows rows: 0x480 / nRows, clamped to 0x20..0x60 (+0x164);
 * (knob - 0x19) / 8 segment widgets 0x18.. are shown and the rest up to 0x20
 * hidden; widgets 0x16..0x20 get their slots released (plain and with frame
 * 0); the caps 0x16 / 0x17 are shown and cap 0x17 placed (knob - 0x10) rows
 * (fx32) below cap 0x16's block position.  Then the panel is laid out at
 * scroll 0 (02074878).
 */

#include "nitro/types.h"

#define SEGMENT_FIRST 0x18
#define SEGMENT_COUNT 9
#define WIDGET_CAP_A  0x16
#define WIDGET_CAP_B  0x17
#define WIDGET_LAST   0x20
#define KNOB_MAX      0x60
#define KNOB_MIN      0x20
#define PANEL_SPAN    0x480

typedef struct UiLayoutPos {
    int nX;
    int nY;
} UiLayoutPos;

typedef struct Ov008DetailPanel {
    u8  pad_000[0x164];
    int nHeight;              /* 0x164: knob length */
} Ov008DetailPanel;

extern int   func_02020400(int nNum, int nDen);                           /* _s32_div_f */
extern int   Ov008_GetCtxBlock4a80(void);                                   /* Ov008_GetCtxBlock4a80 */
extern void *Ov008_FindEntryById(int nCtx, int nId);                      /* FindEntryById */
extern void  Ov008_SetEntrySlotsVisible(int nCtx, void *pEntry, int bVisible);   /* SetEntrySlotsVisible */
extern void  Ov008_ReleaseTwoSlots(int nCtx, void *pEntry);                 /* Ov008_ReleaseTwoSlots */
extern void  Ov008_ReleaseTwoSlotsEx(int nCtx, void *pEntry, int nFrame);     /* Ov008_ReleaseTwoSlotsEx */
extern int  *Ov008_GetEntryBlock2c(int nCtx, void *pEntry);                 /* Ov008_GetEntryBlock2c */
extern void  Ov008_SetEntryPos(int nCtx, void *pEntry, UiLayoutPos *pPos); /* Ov008_SetEntryPos */
extern void  Ov008_DetailPanel_SetScroll(Ov008DetailPanel *pPanel, int nScroll);  /* lay the panel out */

void Ov008_InitDetailPanelKnob(Ov008DetailPanel *pPanel, int nRows)
{
    int nKnob;
    int nSegments;
    int nCtx;
    int i;
    void *pCapA;
    void *pCapB;
    int *pBlock;

    nKnob = func_02020400(PANEL_SPAN, nRows);
    if (nKnob > KNOB_MAX) {
        nKnob = KNOB_MAX;
    }
    if (nKnob < KNOB_MIN) {
        nKnob = KNOB_MIN;
    }
    nSegments = (nKnob - 0x19) / 8;
    nCtx = Ov008_GetCtxBlock4a80();
    {
        UiLayoutPos pos = { 0, 0 };
        for (i = 0; i < nSegments; i++) {
            Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, i + SEGMENT_FIRST), 1);
        }
        for (; i < SEGMENT_COUNT; i++) {
            Ov008_SetEntrySlotsVisible(nCtx, Ov008_FindEntryById(nCtx, i + SEGMENT_FIRST), 0);
        }
        for (i = WIDGET_CAP_A; i <= WIDGET_LAST; i++) {
            Ov008_ReleaseTwoSlots(nCtx, Ov008_FindEntryById(nCtx, i));
            Ov008_ReleaseTwoSlotsEx(nCtx, Ov008_FindEntryById(nCtx, i), 0);
        }
        pCapA = Ov008_FindEntryById(nCtx, WIDGET_CAP_A);
        pCapB = Ov008_FindEntryById(nCtx, WIDGET_CAP_B);
        Ov008_SetEntrySlotsVisible(nCtx, pCapA, 1);
        Ov008_SetEntrySlotsVisible(nCtx, pCapB, 1);
        pBlock = Ov008_GetEntryBlock2c(nCtx, pCapA);
        pos.nX = pBlock[0];
        pos.nY = pBlock[1] + ((nKnob - 0x10) << 12);
        Ov008_SetEntryPos(nCtx, pCapB, &pos);
        pPanel->nHeight = nKnob;
        Ov008_DetailPanel_SetScroll(pPanel, 0);
    }
}
