/* Projectile step: sets the velocity from the action resource's offset and scale in the actor's
 * frame; once the gate byte is clear sends the animation pair from the overlay's table to the
 * actor's event callback, queues action 2 and clears the step handler. */

#include "game/enemy_common.h"

extern void Vec3TransformViaTempMtx(void *dst, void *mtx, int *vec);
extern void ScaleVec3Fx12(int scale, void *v, void *out);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern unsigned short data_ov142_020d2610[];

void Ov142_stTransformProjectilePose(char *obj) {
    int *state = *(int **)(obj + 4);
    short pair[2];
    int vec[3];
    int scale;
    scale = Ov107_ActionResource_GetOffsetAndScale((int)(*(void **)(*state + 0x3cc)), (VecFx32 *)vec);
    Vec3TransformViaTempMtx((void *)(state + 6), (void *)(*state + 0xa0), vec);
    ScaleVec3Fx12(scale, (void *)(state + 6), (void *)(state + 6));
    if (*(unsigned char *)state[0x11] == 0) {
        short *pp = pair;
        void (*cb)();
        pp[1] = data_ov142_020d2610[1];
        pp[0] = data_ov142_020d2610[0];
        cb = *(void (**)())(*state + 0x24);
        if (cb != 0) cb(*state, pp, 4);
        *(signed char *)(*state + 0x1c7) = 2;
        SetIndexedSlot(obj, *(signed char *)(obj + 0x20), (void *)0);
    }
}
