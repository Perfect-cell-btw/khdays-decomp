
#include "nitro/types.h"

typedef int (*Ov002ReserveProc)(char *pCtx, unsigned char bLane, int nKind,
                                u16 wSlot);

extern int GameState_GetField(u16 nId, unsigned char nSlot);
extern char *GetEntryField20ByIndex(unsigned char nIndex);
extern int Ov002_FindKeyEntryIndex(short nId);
extern char *Ov002_GetRootField8d14(short nIndex);
extern void Ov022_Member_ShowSpotMessage(unsigned char nIndex, int nSlot, int nLane);
extern void Ov002_RetireWidget(char *pElement);

/* Hand this element's reserved slot over to a new source.
 *
 * Runs only while the element's game state bit is clear and it has reached
 * stage 3. It asks the owner's reserve proc whether the new source may take
 * the slot; a missing proc counts as a yes. On a refusal it tells the ov022
 * owner and leaves the element alone, otherwise it retires the widget, clears
 * the present bit and latches the new source.
 *
 * The three call arguments are read into locals before the null test on
 * purpose: the original evaluates them unconditionally, above the branch. The
 * order of those three assignments is what fixes the schedule - slot, lane,
 * then kind. */
void *Ov002_ElementHandOverSlot(char *pElement, unsigned char *pSource)
{
    unsigned int nState;
    char *pEntry;
    char *pKey;
    char *pCtx;
    Ov002ReserveProc pProc;
    unsigned char bLane;
    int nKind;
    u16 wSlot;
    int nResult;

    nState = ((unsigned int)(GameState_GetField(*(u16 *)(pElement + 0x14),
                                   *(unsigned char *)(pElement + 0x16))
                             & 0xfffe) << 15) >> 16;

    if ((nState & 1) == 0 && *(unsigned char *)(pElement + 0x1b4) == 3) {
        pEntry = GetEntryField20ByIndex(*pSource);
        pKey = Ov002_GetRootField8d14(
            (short)Ov002_FindKeyEntryIndex(*(short *)(pElement + 0x1b6)));

        pCtx = *(char **)(pEntry + 0x4ec);
        pProc = *(Ov002ReserveProc *)(pCtx + 0x1c0);
        wSlot = *(u16 *)(pKey + 0x40);
        bLane = *(unsigned char *)(pElement + 0x1b9);
        nKind = *(short *)(pKey + 0x42) & 0xff;

        if (pProc == 0) {
            nResult = 1;
        } else {
            nResult = pProc(pCtx, bLane, nKind, wSlot);
        }

        if (nResult == 0) {
            Ov022_Member_ShowSpotMessage(*pSource, *(short *)(pKey + 0x40),
                                *(signed char *)(pElement + 0x1b9));
            return 0;
        }

        Ov002_RetireWidget(pElement);
        *(u16 *)(pElement + 0x12) &= ~8;
        *(unsigned char *)(pElement + 0x1b8) = *pSource;
    }

    return 0;
}
