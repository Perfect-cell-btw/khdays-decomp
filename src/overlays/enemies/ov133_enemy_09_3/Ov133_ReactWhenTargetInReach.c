#include "game/actor.h"
#include "game/ai_task.h"

typedef struct {
    Actor *pSelf;            /* +0x00 */
    char pad04[4];
    Actor *pTarget;          /* +0x08 */
} Owner;

typedef struct {
    AI_TASK_FIELDS(Owner)
} Ctx;

extern Actor *Ov107_FindNearestObject(Actor *self, int *pDistSq);
extern int FX_Sqrt(int x);
extern void SetIndexedSlot(Ctx *ctx, int tag, int c);

void Ov133_ReactWhenTargetInReach(Ctx *ctx) {
    int dist;
    Owner *owner;
    Actor *self;
    Actor *target;
    owner = ctx->pState;

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
    SetIndexedSlot(ctx, ctx->slot, 0);
}
