#include "nitro/types.h"

typedef void (*Ov002NotifyProc)(char *pBase, int nUnit, int nKind, int nId);

extern int Ov002_GetModuleScale(void);
extern int Ov002_AdvanceElementClock(char *pElement, u16 *pTable, int nDelta,
                               int nFlag, int nLimit, int *pCounter);
extern short Session_GetLocalPlayerIndex(void);
extern int Ov002_IsSessionOpen(void);
extern int Ov002_HasAssignedPeerId(void);
extern char *GetEntryField20ByIndex(int nIndex);
extern int Ov002_FindKeyEntryIndex(short nKey);
extern char *Ov002_GetRootField8d14(short nIndex);
extern int GameState_GetField(u16 nId, unsigned char nSlot);
extern void GameState_SetField(u16 nId, unsigned char nSlot, int nValue);
extern void Ov002_SetFieldBit0(char *pElement, int nFlag);
extern void ReleaseNodeResources(char *pNode);
extern void *Ov002_DoneTick(char *pElement);

/* Drive an element that is being taken down.
 *
 * The entry table runs to its limit while the countdown climbs. Once the
 * element reaches the reporting state and the counter passes its threshold,
 * the local player tells the session which unit finished, and the element
 * moves on to the next state. When the table is finally done the game-state
 * field is reduced to its low bit plus two, the node's resources are released
 * and the element hands itself to the retired handler.
 */
void *Ov002_ElementTickTearDown(char *pElement)
{
    int nDelta;
    int bDone;
    char *pSession;
    char *pEntry;
    Ov002NotifyProc pfnNotify;
    u16 wId;
    short nKind;
    unsigned char bUnit;
    int nMasked;
    int nState;

    nDelta = Ov002_GetModuleScale();
    bDone = (Ov002_AdvanceElementClock(pElement, (u16 *)(pElement + 0x3c), nDelta, 0,
                                 0x1e000, (int *)(pElement + 0x1b0)) == 0);

    if (*(unsigned char *)(pElement + 0x1b4) == 5
        && *(int *)(pElement + 0x1b0) >= 0xc000) {

        if (Session_GetLocalPlayerIndex() == 0) {
            if (Ov002_IsSessionOpen() != 0 && Ov002_HasAssignedPeerId() != 0) {

                pSession = GetEntryField20ByIndex(*(unsigned char *)(pElement + 0x1b8));
                pEntry = Ov002_GetRootField8d14(
                    (short)Ov002_FindKeyEntryIndex(*(short *)(pElement + 0x1b6)));

                /* All four values are read before the callback pointer is
                 * tested, and in this order: the original schedules them into
                 * the load-use slots ahead of the branch. */
                wId = *(u16 *)(pEntry + 0x40);
                nKind = *(short *)(pEntry + 0x42);
                nMasked = nKind & 0xff;
                bUnit = *(unsigned char *)(pElement + 0x1b9);
                pfnNotify = *(Ov002NotifyProc *)(
                    *(char **)(pSession + 0x4ec) + 0x1bc);
                if (pfnNotify != 0) {
                    pfnNotify(*(char **)(pSession + 0x4ec), bUnit, nMasked,
                              wId);
                }
            } else {
                return 0;
            }
        }

        *(unsigned char *)(pElement + 0x1b4) = 6;
    }

    if (bDone) {
        nState = GameState_GetField(*(u16 *)(pElement + 0x14),
                               *(unsigned char *)(pElement + 0x16));
        GameState_SetField(*(u16 *)(pElement + 0x14),
                      *(unsigned char *)(pElement + 0x16),
                      (u16)((nState & ~0xfffe) | 2));
        Ov002_SetFieldBit0(pElement, 0);
        ReleaseNodeResources(pElement + 0x2c);
        *(unsigned char *)(pElement + 0x1b4) = 7;
        return Ov002_DoneTick;
    }

    return 0;
}
