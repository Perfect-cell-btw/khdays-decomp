#include "nitro/types.h"

extern int Ov002_IsSessionOpen(void);
extern int Ov002_GetRootField8b68Alt(void);
extern int Ov002_GetSlotTableByte(int nHandle);
extern int VEC_Distance(void *pA, void *pB);

/* Decide whether an actor is close enough to trigger a spare entry.
 *
 * Only the local player counts, and only while the guard allows it. The actor
 * must be on its feet, must be showing something, must hold a real slot, and
 * that slot must be the entry's own bucket. What is left is a distance test
 * against the actor's position.
 */
int Ov002_ElementActorInRange(char *pEntry, char *pActor)
{
    int nFlags;

    if (Ov002_IsSessionOpen() != 0 && Ov002_GetRootField8b68Alt() == 0) {
        nFlags = *(int *)(pActor + 0x464);
        if ((nFlags & 0x10000000) != 0 || (nFlags & 0x8000000) != 0
            || *(u16 *)(pActor + 0x12) == 0) {
            return 0;
        }

        if (*(short *)(pActor + 0x66) >= 0
            && *(unsigned char *)(pEntry + 0x10)
                   == Ov002_GetSlotTableByte(*(short *)(pActor + 0x66))) {
            if (VEC_Distance(pEntry + 0x1c, pActor + 0x48c) <= 0xc00) {
                return 1;
            }
        }
    }

    return 0;
}
