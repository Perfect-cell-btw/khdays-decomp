
/* Hand back the node's payload when it is visible, not suppressed, and its
 * state query does not report the blocking bit. Slot 2 skips the query.
 *
 * Three forms are load-bearing. The two guards are nested rather than joined
 * with &&, so each keeps its own branch to the shared exit. The extraction is
 * shifted through unsigned, which is what makes the second shift an lsr. And
 * the mask lives inside the else arm, not in the shared test: the original
 * branches straight past the and on the slot-2 path, so the join compares a
 * plain variable against zero. */

#include "game/engine.h"

char *Ov002_GetNodePayload(char *pNode)
{
    unsigned char nSlot;
    unsigned int nBits;

    if ((*(unsigned short *)(pNode + 0x12) & 8) != 0) {
        if ((*(unsigned char *)(pNode + 0x1bb) & 0x40) == 0) {

        nSlot = *(unsigned char *)(pNode + 0x16);
        if (nSlot == 2) {
            nBits = 0;
        } else {
            nBits = (((unsigned int)(GameState_GetField(*(unsigned short *)(pNode + 0x14), nSlot)
                                    & 0xfffe) << 15) >> 16) & 4;
        }

        if (nBits == 0) {
            goto payload;
        }
        }
    }

    return 0;

payload:
    return pNode + 0x1c;
}
