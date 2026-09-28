/* Advance one armed entry. Re-reads the sampler: while the reading is unchanged
 * the accumulator collects the elapsed ticks, and the moment it changes both the
 * accumulator and the stored reading are reset to the new value. The stamp is
 * always refreshed. Passing a non-zero flag also repaints the entry.
 */
#include "nitro/types.h"

typedef struct {
    u8 pad0000[0x2c];
    long long qwAccum;                  /* +0x2c */
    long long qwSample;                 /* +0x34 */
    u8 pad003c[8];
    unsigned long long qwSampledAt;     /* +0x44 */
    long long (*pfnSample)(void);       /* +0x4c */
    int bSampling;                      /* +0x50 */
} Ov002PoolEntry;

extern unsigned long long OS_GetTick(void);
extern void Ov002_RepaintStopwatchEntry(Ov002PoolEntry *pEntry);

void Ov002_AccumulateEntrySample(Ov002PoolEntry *pEntry, int bRefresh) {
    long long qwNow = pEntry->pfnSample();
    unsigned long long qwTick = OS_GetTick();

    if (pEntry->bSampling == 0) {
        return;
    }

    if (pEntry->qwSample == qwNow) {
        pEntry->qwAccum = pEntry->qwAccum + (qwTick - pEntry->qwSampledAt);
    } else {
        pEntry->qwAccum = qwNow;
        pEntry->qwSample = qwNow;
    }
    pEntry->qwSampledAt = qwTick;

    if (bRefresh == 0) {
        return;
    }
    Ov002_RepaintStopwatchEntry(pEntry);
}
