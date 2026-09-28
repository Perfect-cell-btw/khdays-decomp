/* Add to a counter entry on behalf of its owner. A mismatched owner releases the
 * entry instead and reports that it is gone. On a match the running total grows,
 * the entry's deadline is pushed one second out, and the new total is redrawn.
 *
 * The 0x24 and 0x2c slots are shared with the stopwatch kinds, which read the
 * same bytes as one 64-bit accumulator; here they are a deadline and a pair of
 * 32-bit fields.
 */
#include "nitro/types.h"

typedef struct {
    u8 pad0000[0x24];
    unsigned long long qwDeadline;      /* +0x24 */
    int nValue;                         /* +0x2c */
    int nOwner;                         /* +0x30 */
} Ov002PoolEntry;

extern unsigned long long OS_GetTick(void);
extern void Ov002_ReleasePoolEntry(Ov002PoolEntry *pEntry, int bNotify);
extern void Ov002_RenderDecimalIntoEntry(Ov002PoolEntry *pEntry, int nValue);

int Ov002_BumpCounterEntry(Ov002PoolEntry *pEntry, int nDelta, int nOwner) {
    int bAlive = 1;

    if (pEntry->nOwner != nOwner) {
        Ov002_ReleasePoolEntry(pEntry, bAlive);
        bAlive = 0;
    } else {
        pEntry->nValue = pEntry->nValue + nDelta;
        pEntry->qwDeadline = OS_GetTick() + 523656;
        Ov002_RenderDecimalIntoEntry(pEntry, pEntry->nValue);
    }
    return bAlive;
}
