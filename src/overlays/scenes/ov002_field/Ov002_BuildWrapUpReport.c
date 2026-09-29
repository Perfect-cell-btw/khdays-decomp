
#include "nitro/types.h"
#include "game/engine.h"

extern char *data_ov002_0207fa00;   /* the ov002 root context */

extern char *Slot4_GetIfOccupied(int nSlot);  /* Slot4_GetIfOccupied */

/* Fills the wrap-up report the session board hands to the results side.
 *
 * Walks the card slots and, for each one that is occupied, writes the running
 * index and the slot's own field into the head of the report, then four
 * halfwords from the next seat: its figure, clamped to 9999, and the three
 * words after it.  How many seats were written lands in the first halfword.
 *
 * The seat cursor only advances on an occupied slot, so the seats are packed
 * against the slots that are actually in, and the figure is clamped to 9999 on
 * the way into its halfword.
 *
 * The pragma is what keeps the header address recomputed from the stack each
 * time: written plainly, mwcc turns it into a walking pointer and spends a
 * register on it, which costs the slot the loop counter needs.  The same
 * pragma is already used around Ov002_FillScreenBlock and two ov000 functions.
 */
#pragma opt_strength_reduction off
void Ov002_BuildWrapUpReport(u16 *pReport)
{
    char *pAccessor;
    u16 *pOut;
    int i;
    char *pSeat;
    int nFigure;
    char *pSlot;
    int nCount;

    pSeat = data_ov002_0207fa00 + 0x8bcc;
    pAccessor = Session_GetSlotTable();
    nCount = 0;
    i = 0;
    if (*(int *)(pAccessor + 4) > 0) {
        pOut = (u16 *)((char *)pReport + 0xa);
        do {
            pSlot = Slot4_GetIfOccupied(i);
            if (pSlot != 0) {
                *((u8 *)pReport + nCount + 2) = (u8)nCount;
                *((u8 *)pReport + nCount + 6) = (u8)*(int *)(pSlot + 4);
                nFigure = *(int *)(pSeat + 0x24);
                if (nFigure > 9999) {
                    nFigure = 9999;
                }
                pOut[0] = (u16)nFigure;
                nCount++;
                pOut[1] = (u16)*(int *)(pSeat + 0x28);
                pOut[2] = (u16)*(int *)(pSeat + 0x2c);
                pOut[3] = (u16)*(int *)(pSeat + 0x30);
                pSeat += 0x2c;
                pOut += 4;
            }
            i++;
        } while (i < *(int *)(pAccessor + 4));
    }
    *pReport = (u16)nCount;
}
#pragma opt_strength_reduction on
