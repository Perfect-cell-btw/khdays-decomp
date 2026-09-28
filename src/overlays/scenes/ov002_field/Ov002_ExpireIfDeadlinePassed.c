/* Expire the entry once its deadline has passed. The deadline is a 64-bit tick
 * count at +0x24, compared against the current tick with the usual cmp/cmpeq
 * pair -- high words first, low words only if the high words agree. */
extern unsigned long long OS_GetTick(void);
extern void Ov002_ReleasePoolEntry(void *self, int reason);

typedef struct {
    char pad0000[0x24];
    unsigned long long qwDeadline;  /* +0x24 */
} Ov002TimedEntry;

void Ov002_ExpireIfDeadlinePassed(Ov002TimedEntry *self) {
    if (self->qwDeadline > OS_GetTick()) {
        return;
    }

    Ov002_ReleasePoolEntry(self, 1);
}
