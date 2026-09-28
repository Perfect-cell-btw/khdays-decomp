/* Repaint one group of six list-backed panel rows -- the list sibling of the
 * plain group repaint.
 *
 * The code is classified into a class index, the list is entered at ordinal
 * class*6, and up to six entries are walked from there. A row draws enabled
 * only when both group filters accept its key, and the row the panel's kind
 * points at is drawn right-aligned. Whatever slots the list could not fill are
 * repainted as empty rows. Finally the group's header widget is fetched by tag
 * and invoked.
 *
 * Two codegen notes. The walk is a guarded do/while rather than a plain while:
 * the ROM tests the first entry once up front and then re-tests the slot count
 * before the entry at the bottom, which is the shape a leading while() does not
 * produce. And the right-align flag has to be computed into its own local
 * before the slot lookup -- left in the argument list it is evaluated after the
 * call, and the ROM does it before.
 */

#include "nitro/types.h"

typedef struct {
    void *pHead;
    void *pTail;
    u16 nCount;
    u16 nLinkOffset;
} NNSFndList;

typedef struct {
    u16 nKey;               /* +0x00 */
    u16 nTag;               /* +0x02 */
} Ov002PanelEntry;

typedef struct {
    u8 bKind;                   /* +0x00 */
    u8 pad0001[0x0f];
    int nState;                 /* +0x10 */
    u8 pad0014[0x46c];
    NNSFndList lists[3];        /* +0x480 */
} Ov002PanelSession;

extern Ov002PanelSession *data_ov002_0207f620;

extern void Ov002_ClassifyCode(int *pOut, int nCode);
extern int Ov002_Panel_IsSlotEnabledA(int nGroup, int nKey);
extern int Ov002_Panel_IsSlotEnabledB(int nGroup, int nKey);
extern int Ov002_FindSlotByKey(int nKey);
extern void Ov002_PanelRepaintListRow(NNSFndList *pList, int nIndex, int nSlot,
                                int nEntry, int nColumn, int bEnabled,
                                int bRightAlign, int bAlt);
extern int Ov002_ForwardToSubDc(int nTag);
extern void Ov002_PositionSubDcHandle_2(int nHandle, int nValue, int nKind);
extern void Ov002_Ctx_InvokeTagTrackerCallback(int nHandle);
extern void Ov002_SelectEntry(int nItemId);
extern Ov002PanelEntry *NNS_FndGetNthListObject(NNSFndList *pList, u16 nIndex);
extern Ov002PanelEntry *NNS_FndGetNextListObject(NNSFndList *pList,
                                                 Ov002PanelEntry *pObject);

void Ov002_PanelRepaintListGroup(int nCode) {
    int nClass;
    Ov002PanelSession *s;
    int i;
    Ov002PanelEntry *pEntry;
    int nHandle;

    s = data_ov002_0207f620;
    i = 0;
    Ov002_ClassifyCode(&nClass, nCode);
    pEntry = NNS_FndGetNthListObject(&s->lists[0], nClass * 6);

    if (pEntry != 0) {
        do {
            int bEnabled = Ov002_Panel_IsSlotEnabledA(0, pEntry->nKey) != 0 &&
                           Ov002_Panel_IsSlotEnabledB(0, pEntry->nKey) != 0;
            int bRight = s->bKind == i;
            int nIndex = Ov002_FindSlotByKey(pEntry->nKey);

            Ov002_PanelRepaintListRow(&s->lists[0], nIndex, i, nClass * 6 + i, 1,
                                bEnabled, bRight, 0);
            i++;
            pEntry = NNS_FndGetNextListObject(&s->lists[0], pEntry);
        } while (i < 6 && pEntry != 0);
    }

    for (; i < 6; i++) {
        Ov002_PanelRepaintListRow(&s->lists[0], -1, i, 0, 1, 0, s->bKind == i, 0);
    }

    if (s->nState != 0) {
        nHandle = Ov002_ForwardToSubDc(0x59);
    } else {
        nHandle = Ov002_ForwardToSubDc(0x5e);
    }
    Ov002_PositionSubDcHandle_2(nHandle, 1, 0xa);
    Ov002_Ctx_InvokeTagTrackerCallback(nHandle);
    Ov002_SelectEntry(0xb);
}
