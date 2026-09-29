/* Ov008_MissionListConfirm -- Ov008_MissionListConfirm: the mission list's "confirm"
 * handler.  Ignored while the list is animating.  With nothing selected and no
 * selection pending it opens the detail panel (confirm sound) and clears the two
 * scroll counters; with a selection pending but not yet armed it closes the panel
 * again (cancel sound); otherwise, unless a transfer is in flight but not
 * acknowledged, it runs the selection step.
 */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct Ov008MissionList {
    int nSelected;            /* 0x000: -1 = none */
    u8  pad_004[0x30 - 0x04];
    int nScrollA;             /* 0x030 */
    int nScrollB;             /* 0x034 */
    u8  pad_038[0x40 - 0x38];
    int bTransfer;            /* 0x040 */
    int bTransferAcked;       /* 0x044 */
    u8  pad_048[0x68 - 0x48];
    int bAnimating;           /* 0x068 */
    u8  pad_06c[0x4f8 - 0x6c];
    int bSelectionPending;    /* 0x4f8 */
    int bSelectionArmed;      /* 0x4fc */
} Ov008MissionList;

#define NO_SELECTION  -1
#define SOUND_CONFIRM 1
#define SOUND_CANCEL  3

extern void Ov008_ShowMissionListInfoPanel(Ov008MissionList *pList, int bExpand);   /* detail panel slide */
extern void Ov008_MissionListSelect(Ov008MissionList *pList);                 /* selection step */

void Ov008_MissionListConfirm(Ov008MissionList *pList)
{
    if (pList->bAnimating != 0) {
        return;
    }
    if (pList->bSelectionPending == 0 && pList->nSelected == NO_SELECTION) {
        Ov008_ShowMissionListInfoPanel(pList, 1);
        PlaySound(0, SOUND_CONFIRM);
        pList->nScrollA = 0;
        pList->nScrollB = 0;
        return;
    }
    if (pList->bSelectionPending != 0 && pList->bSelectionArmed == 0) {
        Ov008_ShowMissionListInfoPanel(pList, 0);
        PlaySound(0, SOUND_CANCEL);
        return;
    }
    if (pList->bTransfer != 0 && pList->bTransferAcked == 0) {
        return;
    }
    Ov008_MissionListSelect(pList);
}
