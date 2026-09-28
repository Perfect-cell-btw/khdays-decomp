#include "game/actor.h"

typedef struct {
    Actor *pSelf;            /* +0x00 */
    char pad04[4];
    Actor *pTarget;          /* +0x08 */
} Owner;

typedef struct {
    char pad00[4];
    Owner *pOwner;           /* +0x04 */
    char pad08[0x18];
    signed char bTag;        /* +0x20 */
} Ctx;

extern Actor *Ov107_FindNearestObject(Actor *self, int *pDistSq);
extern int FX_Sqrt(int x);
extern void SetIndexedSlot(Ctx *ctx, int tag, int c);

void Ov161_ReactWhenTargetInReach(Ctx *ctx) {
    int dist;
    Owner *owner;
    Actor *self;
    Actor *target;
    owner = ctx->pOwner;

    owner->pTarget = Ov107_FindNearestObject(owner->pSelf, &dist);
    target = owner->pTarget;
    if (target == 0) {
        return;
    }
    self = owner->pSelf;
    dist = FX_Sqrt(dist) - (target->sphere.radius + self->sphere.radius);
    if (dist > owner->pSelf->range) {
        return;
    }
    owner->pSelf->nextState = 4;
    SetIndexedSlot(ctx, ctx->bTag, 0);
}
