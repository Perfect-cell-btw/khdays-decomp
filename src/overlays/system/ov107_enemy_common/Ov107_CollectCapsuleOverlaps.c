/* Collects the owner's container entries whose capsule (+0x78 of their shape) is within its radius
 * of the position. */

#include "game/actor.h"

extern int List_First(void *list);
extern int List_Next(void *list);
extern int Capsule_ClosestToBox(void *a, void *b, int c, int d, int e, int f);
extern int FX_Sqrt(int x);

typedef struct { int w[8]; } Blk32;

typedef struct {
    char pad0[4];
    void *owner;            /* +4 */
    char pad8[0x1d8 - 8];
    char *shape;             /* +0x1d8 */
} Entry;

int Ov107_CollectCapsuleOverlaps(Actor *self, void *position, void **outArray)
{
    char *owner = self->pScene;
    int count = 0;
    void *outerIt;
    Entry *cand;

    outerIt = (void *)List_First(owner + 0xa8);
    cand = !outerIt ? 0 : *(Entry **)outerIt;

    while (cand != 0) {
        if (cand->owner == self->pScene) {
            Blk32 blk = *(Blk32 *)(cand->shape + 0x78);
            int dist = Capsule_ClosestToBox(&blk, position, 0, 0, 0, 0);
            int d = FX_Sqrt(dist);
            if (d <= blk.w[7]) {
                outArray[count] = cand;
                count++;
            }
        }
        outerIt = (void *)List_Next(owner + 0xa8);
        cand = !outerIt ? 0 : *(Entry **)outerIt;
    }

    return count;
}
