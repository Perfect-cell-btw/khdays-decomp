/* AI step: sets the velocity from the action resource's offset and scale in the actor's frame; once
 * the gate byte is clear installs the next step. */

#include "game/engine.h"

extern void ScaleVec3Fx12(int factor, void *src, void *dst);
extern void SetIndexedSlot(void *node, int idx, void *value);
extern int Ov107_ActionResource_GetOffsetAndScale(void *obj, int *vec);
extern void Ov204_Action7IfHitFlagsSet(void);

void Ov204_TransformScaleThenAdvance(int node)
{
    int vec[3];
    int *state = *(int **)(node + 4);
    int factor = Ov107_ActionResource_GetOffsetAndScale(*(void **)(*state + 0x390), vec);

    Vec3TransformViaTempMtx((void *)(state + 2), (void *)(*state + 0xa0), vec);
    ScaleVec3Fx12(factor, state + 2, state + 2);
    if (*(unsigned char *)state[0x28 / 4] != 0) {
        return;
    }
    SetIndexedSlot((void *)node, *(signed char *)(node + 0x20), Ov204_Action7IfHitFlagsSet);
}
