/*
 * Ov002_PanelActivateSlot - decide what pressing A on the current slot does.
 *
 * The slot the cursor sits on names an action, and the answer is the group the
 * panel should switch to. Most actions just move the cursor somewhere and hand
 * back the empty group; two of them (5 and 6) name a group of their own; the
 * two keyed ones look their entry up in a list and only accept it while it
 * passes both key tests, buzzing back to empty when it does not. Action 4 also
 * caches the entry it found and records whether it is usable before opening it.
 *
 * Whatever the slot decided, a cell group is re-checked at the end: if the cell
 * the cursor is on is not live, that too buzzes back to empty.
 *
 * THUMB.
 */

#include "nitro/types.h"

typedef struct {
    u16 wKey;                           /* +0x00 */
    u16 pad0002;
    int nCount;                         /* +0x04 */
} Ov002PanelSubEntry;

typedef struct {
    u8 bKind;                           /* +0x000 */
    u8 pad0001;
    u8 bIndex;                          /* +0x002 */
    u8 bListIndex;                      /* +0x003 */
    u8 bKey;                            /* +0x004 */
    u8 pad0005[2];
    u8 bDefaultKind;                    /* +0x007 */
    u8 pad0008[4];
    int nPrimaryValue;                  /* +0x00c */
    u8 pad0010[0xa];
    u16 aSlots[0x233];                  /* +0x01a */
    u8 aLists[0x18];                    /* +0x480 */
    u8 aThirdList[0xc];                 /* +0x498 */
    Ov002PanelSubEntry *pCachedEntry;   /* +0x4a4 */
} Ov002PanelSession;

extern Ov002PanelSession *data_ov002_0207f620;

extern void PlaySoundChecked(int nId, int nKind);
extern Ov002PanelSubEntry *NNS_FndGetNthListObject(void *pList, unsigned int nIndex);

extern int Ov002_GetPanelField0058(void);
extern int Ov002_CountPanelListEntries(void);
extern int Ov002_CountSecondListEntries(void);
extern int Ov002_Panel_IsSlotUsable(int nCell);
extern int Ov002_Panel_IsSlotEnabledA(int nGroup, unsigned int nKey);
extern int Ov002_Panel_IsSlotEnabledB(int nGroup, unsigned int nKey);
extern void Ov002_HandlePanelInput(int nTarget, int nValue);

int Ov002_PanelActivateSlot(void)
{
    Ov002PanelSession *s;
    Ov002PanelSubEntry *pEntry;
    int nGroup;
    int nKey;
    int nFlag;

    s = data_ov002_0207f620;
    nGroup = s->aSlots[s->bKind];
    switch (nGroup) {
    case 9:
        if (s->nPrimaryValue == 0) {
            if (Ov002_GetPanelField0058() != 0) {
                nGroup = 7;
            }
            PlaySoundChecked(0, 4);
        }
        break;

    case 0:
        Ov002_HandlePanelInput(0, 3);
        nGroup = 7;
        break;

    case 1:
        nGroup = 7;
        Ov002_HandlePanelInput(1, 2);
        break;

    case 3:
        pEntry = NNS_FndGetNthListObject(s->aLists, s->bListIndex);
        if (pEntry == 0
            || Ov002_Panel_IsSlotEnabledA(0, pEntry->wKey) == 0
            || Ov002_Panel_IsSlotEnabledB(0, pEntry->wKey) == 0) {
            nGroup = 7;
            PlaySoundChecked(0, 4);
        } else {
            nGroup = 0xb;
        }
        break;

    case 2:
        nGroup = 7;
        if (Ov002_CountPanelListEntries() > 0) {
            Ov002_HandlePanelInput(4, 2);
        } else if (Ov002_CountSecondListEntries() > 0) {
            Ov002_HandlePanelInput(6, 2);
        }
        break;

    case 4:
        nGroup = 7;
        s->pCachedEntry = NNS_FndGetNthListObject(s->aThirdList, s->bKey);
        pEntry = s->pCachedEntry;
        nKey = pEntry->wKey;
        if (pEntry == 0) {
            PlaySoundChecked(0, 4);
        } else {
            if (pEntry->nCount == 0
                || Ov002_Panel_IsSlotEnabledA(0, nKey) == 0
                || Ov002_Panel_IsSlotEnabledB(0, nKey) == 0) {
                nFlag = 1;
            } else {
                nFlag = 0;
            }
            s->bDefaultKind = (u8)nFlag;
            Ov002_HandlePanelInput(10, 2);
        }
        break;

    case 5:
        nGroup = 0xc;
        break;

    case 6:
        nGroup = 0xd;
        break;

    case 7:
    case 8:
    case 10:
    case 11:
        break;
    }

    if (nGroup == 8 && Ov002_Panel_IsSlotUsable(s->bIndex) == 0) {
        nGroup = 7;
        PlaySoundChecked(0, 4);
    }
    return nGroup;
}
