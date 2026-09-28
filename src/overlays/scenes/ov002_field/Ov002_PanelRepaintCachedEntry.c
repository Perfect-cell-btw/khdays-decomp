/* Repaint the panel around the cached sub-entry: highlight the slot it lives
 * in, colour the confirm label by whether the entry is actually usable, and
 * flip the confirm/cancel pair to whichever side the current kind wants. */
#include "nitro/types.h"

typedef struct {
    u16 nKey;
    u16 nTag;
    void *pObject;
    u8 pad0008[0x10];
} Ov002PanelSubEntry;

typedef struct {
    u8 pad0000[7];
    u8 bDefaultKind;                /* +0x7 */
    u8 pad0008[0x49c];
    Ov002PanelSubEntry *pCachedEntry;   /* +0x4a4 */
} Ov002PanelSession;

extern Ov002PanelSession *data_ov002_0207f620;

extern int Ov002_ForwardToSubDc(int nId);
extern void Ov002_Ctx_InvokeTagTrackerCallback(int nEntry);
extern int Ov002_Panel_IsSlotEnabledA(int nGroup, int nKey);
extern int Ov002_Panel_IsSlotEnabledB(int nGroup, int nKey);
extern int Ov002_FindSlotByKey(int nKey);
extern void Ov002_PanelWriteSlotLabel(int nSlot, int nSub, u16 wValue, u16 nColour,
                                int bFlag);
typedef enum {
    PANEL_SIDE_LEFT = 0,
    PANEL_SIDE_RIGHT = 1
} Ov002PanelSide;

extern void Ov002_PanelPushSlotState(int nSlot, Ov002PanelSide eSide, int nFlag);
extern void Ov002_SelectEntry(int nId);

void Ov002_PanelRepaintCachedEntry(void) {
    Ov002PanelSession *s = data_ov002_0207f620;
    int bRightAlign = (s->bDefaultKind == 0);
    Ov002PanelSubEntry *pEntry;
    int nKey;
    int nColour;

    Ov002_Ctx_InvokeTagTrackerCallback(Ov002_ForwardToSubDc(0x65));

    pEntry = s->pCachedEntry;
    nKey = pEntry->nKey;
    if (pEntry->pObject != 0 &&
        Ov002_Panel_IsSlotEnabledA(0, nKey) != 0 &&
        Ov002_Panel_IsSlotEnabledB(0, nKey) != 0) {
        nColour = 0xf;
    } else {
        nColour = 0xe;
    }

    Ov002_PanelWriteSlotLabel(3, 0, (u16)(Ov002_FindSlotByKey(nKey) * 0x10 + 0x250),
                        0xf, 0);
    Ov002_PanelWriteSlotLabel(4, 0, 0x3e0, (u16)nColour, bRightAlign);
    Ov002_PanelWriteSlotLabel(5, 0, 0x3f0, 0xf, bRightAlign == 0);
    Ov002_PanelPushSlotState(4, bRightAlign != 0 ? PANEL_SIDE_LEFT : PANEL_SIDE_RIGHT, 0);
    Ov002_PanelPushSlotState(5, bRightAlign != 0 ? PANEL_SIDE_RIGHT : PANEL_SIDE_LEFT, 0);
    Ov002_SelectEntry(9);
}
