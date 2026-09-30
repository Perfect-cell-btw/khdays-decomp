/* Transforms the offset (+0x18) through the owner's matrix and scales it; once the animation ends
 * queues action 2 and ends the step. */

#include "game/ai_task.h"
#include "game/engine.h"

extern int Ov107_ActionResource_GetOffsetAndScale();
extern int ScaleVec3Fx12();
extern int SetIndexedSlot();

struct S0 {
    AI_TASK_FIELDS(int)
};

struct Local { int a; int b; int c; };

void Ov269_AiTrackOffsetUntilAnimEnd_3(struct S0 *this)
{
    struct Local local;
    int *r6 = this->pState;
    int r5;

    r5 = Ov107_ActionResource_GetOffsetAndScale(((int **)r6[0])[0xf4], &local);
    Vec3TransformViaTempMtx((char *)r6 + 0x18, (char *)r6[0] + 0xa0, &local);
    ScaleVec3Fx12(r5, (char *)r6 + 0x18, (char *)r6 + 0x18);

    if (*((unsigned char *)((int *)r6[1]) + 0xad) != 0)
        return;

    *((char *)r6[0] + 0x1c7) = 2;
    SetIndexedSlot(this, (int)*((signed char *)this + 0x20), 0);
}
