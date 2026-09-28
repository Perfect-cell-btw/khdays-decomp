
/* The queue record the collector fills in; only the value field is ours. */

#include "nitro/types.h"

typedef struct {
    unsigned char bKind;            /* +0x00 filled by the collector */
    unsigned char bSource;          /* +0x01 filled by the collector */
    u16 wIndex;                     /* +0x02 filled by the collector */
    u16 wValue;                     /* +0x04 */
    u16 wPad;                       /* +0x06 */
} Ov002HitRecord;

extern int GameState_GetField(int nId, int nSlot);
extern void GameState_SetField(unsigned int nId, unsigned int nSlot, unsigned int wState);
extern int Ov002_RecordElementHit(char *pElement, Ov002HitRecord *pRecord, int nKind);

/* Register a hit on this element once.
 *
 * The element names a field in the game state bit array: wStateField is the
 * bit offset and bStateWidth the width. Bit 0 of that field marks the element
 * already registered. The call refuses with 8 when the bit is set or when the
 * collector will not take the record; otherwise it queues the record, sets the
 * bit and reports 0.
 *
 * Three spellings are load-bearing. The two refusals differ on purpose - the
 * first is a goto to a shared block, the second a plain return that mwcc
 * predicates in place, which is the asymmetry the original has. The write-back
 * takes the query into its own statement and expresses the field as a u16
 * shifted up by one, which is what mwcc folds into the lsl 16 / lsr 15 pair
 * and what colours the pool constant into the higher register. The read, by
 * contrast, must keep the explicit double shift: spelling it as a u16 costs
 * four bytes. */int Ov002_TryRegisterElementHit(char *pElement, char *pHitSource)
{
    unsigned int nState;
    unsigned char nValue;
    unsigned int nField;
    unsigned int nRaw;
    u16 wNew;
    Ov002HitRecord rec;

    nState = ((unsigned int)(GameState_GetField(*(u16 *)(pElement + 0x14),
                                   *(unsigned char *)(pElement + 0x16))
                             & 0xfffe) << 15) >> 16;

    if ((nState & 1) != 0) {
        goto refuse;
    }

    nValue = *(unsigned char *)(pHitSource + 0xc);
    rec.wValue = nValue;

    if (Ov002_RecordElementHit(pElement, &rec, 6) == 0) {
        return 8;
    }

    nRaw = GameState_GetField(*(u16 *)(pElement + 0x14), *(unsigned char *)(pElement + 0x16));
    nField = (u16)(nState | 1) << 1;
    wNew = (u16)(nField | (nRaw & 0xffff0001));

    GameState_SetField(*(u16 *)(pElement + 0x14), *(unsigned char *)(pElement + 0x16), wNew);
    return 0;

refuse:
    return 8;
}
