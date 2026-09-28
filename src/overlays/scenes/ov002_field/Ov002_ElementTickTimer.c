
/* The queue record this element hands to the collector. */

#include "nitro/types.h"

typedef struct {
    unsigned char bTag;             /* +0x00 */
    unsigned char bPad0[3];
    int nParam;                     /* +0x04 */
    unsigned char bSlot;            /* +0x08 */
    unsigned char bFlag;            /* +0x09 */
    unsigned char bPad1[2];
} Ov002TimeoutRecord;

extern int Ov002_GetModuleScale(void);
extern short Session_GetLocalPlayerIndex(void);
extern int GameState_GetField(u16 nId, unsigned char nSlot);
extern int Ov002_RecordElementHit(char *pElement, Ov002TimeoutRecord *pRecord,
                               int nKind);
extern void Ov002_SetFrameOnActiveTracks(u16 *pTable, int nTime);
extern void Ov002_ElementRetire(char *pElement);

/* Drive a timed element for one frame.
 *
 * While the element is counting down and its game state bit is set, and only
 * for the local player on an enabled owner, the countdown is reduced by the
 * module scale; when it runs out a timeout record is queued and the element is
 * marked reported. In the finishing phase the elapsed counter is advanced
 * instead, the entry table is driven from it, and the element is retired once
 * it reaches the owner's track limit.
 *
 * Two orderings are load-bearing: the record's fields are written tag, slot,
 * flag, then parameter - not in offset order - and the finish test compares
 * the elapsed counter against the limit, not the other way round. */
void *Ov002_ElementTickTimer(char *pElement)
{
    char *pOwner;
    int nDelta;
    int nTime;
    int nLimit;
    Ov002TimeoutRecord rec;

    pOwner = *(char **)(pElement + 8);
    nDelta = Ov002_GetModuleScale();

    if (Session_GetLocalPlayerIndex() == 0
        && *(u16 *)(pOwner + 0x7c) != 0
        && *(unsigned char *)(pElement + 0x1b9) == 0
        && ((((unsigned int)(GameState_GetField(*(u16 *)(pElement + 0x14),
                                    *(unsigned char *)(pElement + 0x16))
                             & 0xfffe) << 15) >> 16) & 1) == 1) {

        nTime = *(int *)(pElement + 0x1b0) - nDelta;
        *(int *)(pElement + 0x1b0) = nTime;

        if (nTime < 0) {
            rec.bTag = 1;
            rec.bSlot = 0xff;
            rec.bFlag = 0;
            rec.nParam = 0;

            if (Ov002_RecordElementHit(pElement, &rec, 12) != 0) {
                *(unsigned char *)(pElement + 0x1b9) = 1;
            }

            *(int *)(pElement + 0x1b0) = -1;
        }
    } else if (*(unsigned char *)(pElement + 0x1b9) == 2) {
        nLimit = *(int *)(pOwner + *(unsigned char *)(pElement + 0x1b8) * 4 + 0x84);

        if ((*(u16 *)(pElement + 0x12) & 4) != 0) {
            Ov002_SetFrameOnActiveTracks((u16 *)(pElement + 0x3c),
                                *(int *)(pElement + 0x1b4));
        }

        nLimit -= 0x1000;
        nTime = *(int *)(pElement + 0x1b4) + nDelta;
        *(int *)(pElement + 0x1b4) = nTime;

        if (nTime >= nLimit) {
            if ((*(u16 *)(pElement + 0x12) & 4) != 0) {
                Ov002_SetFrameOnActiveTracks((u16 *)(pElement + 0x3c), nLimit);
            }
            Ov002_ElementRetire(pElement);
        }
    }

    return 0;
}
