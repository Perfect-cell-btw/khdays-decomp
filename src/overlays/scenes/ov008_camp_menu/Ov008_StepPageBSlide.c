/* Ov008_StepPageBSlide -- Ov008_StepPageBSlide: per-frame step of page B's slide.
 * While the entry is busy the slide tween is sampled into the panel offset and the
 * sub screen brightness follows the offset (>> 12); otherwise brightness 0.  A
 * closing panel (state 2) whose tween has finished (bit 2 of the tween word) and
 * whose transfer word is clear loads the sub background, rebuilds the entry and
 * refreshes; an opening panel (state 1) whose tween has finished returns to idle.
 * The done flag is a 1-bit field (extract + movs), not a mask test.
 */
#include "nitro/types.h"

typedef struct Ov008PageB {
    u8  pad_000[0x10];
    u8  tween[0x18];          /* 0x010: slide tween; +0x18 (=0x28) holds the state bits */
    unsigned int nTweenPad : 2; /* 0x028 */
    unsigned int bTweenDone : 1;  /* bit 2 = finished */
    unsigned int nTweenRest : 29;
    int nOffset;              /* 0x02c */
    u8  pad_030[0x1f0 - 0x30];
    int nTransfer;            /* 0x1f0 */
    u8  pad_1f4[4];
    int nPanelState;          /* 0x1f8 */
} Ov008PageB;

#define PANEL_IDLE    0
#define PANEL_OPENING 1
#define PANEL_CLOSING 2

extern Ov008PageB *Ov008_GetPageB(void);                 /* Ov008_GetPageB */
extern int Ov008_IsEntryBusyOrInactive(void);                         /* Ov008_IsEntryBusyOrInactive */
extern void Tween_Sample(void *pTween, int *pValue);         /* Tween_Sample */
extern int Ov008_PageB_GetScrollRow(void);                         /* panel offset >> 12 */
extern void SetMasterBrightnessSub(int nBrightness);                   /* SetMasterBrightnessSub */
extern void Ov008_LoadMenuSubBg2(int nWhich);                  /* Ov008_LoadMenuSubBg2 */
extern void Ov008_PageB_Redraw(void);
extern void Ov008_PageB_StartScrollReset(void);

void Ov008_StepPageBSlide(void)
{
    Ov008PageB *pPage = Ov008_GetPageB();
    int nBrightness;

    if (Ov008_IsEntryBusyOrInactive() == 0) {
        nBrightness = 0;
    } else {
        Tween_Sample(pPage->tween, &pPage->nOffset);
        nBrightness = Ov008_PageB_GetScrollRow();
    }
    SetMasterBrightnessSub(nBrightness);
    if (pPage->nPanelState == PANEL_CLOSING && pPage->bTweenDone != 0
        && pPage->nTransfer == 0) {
        Ov008_LoadMenuSubBg2(0);
        Ov008_PageB_Redraw();
        Ov008_PageB_StartScrollReset();
    }
    if (pPage->nPanelState == PANEL_OPENING) {
        if (pPage->bTweenDone != 0) {
            pPage->nPanelState = PANEL_IDLE;
        }
    }
}
