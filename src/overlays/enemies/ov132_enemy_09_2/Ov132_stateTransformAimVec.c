/* AI step: sets the velocity from the action resource's offset and scale in the actor's frame; once
 * the gate byte is clear sends the animation pair from the overlay's table to the actor's event
 * callback, posts pose 10, sets the dash speed and installs the homing-dash step. */

#include "game/enemy_common.h"

extern void Vec3TransformViaTempMtx(void *dst, void *mtx, int *vec);
extern void ScaleVec3Fx12(int scale, void *v, void *out);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern unsigned short data_ov132_020d0d8c[];
extern void Ov132_HomingDash_Tick(void);

void Ov132_stateTransformAimVec(char *obj) {
    int *state = *(int **)(obj + 4);
    short pair[2];
    int vec[3];
    int scale;
    scale = Ov107_ActionResource_GetOffsetAndScale((int)(*(void **)(*state + 0x3c8)), (VecFx32 *)vec);
    Vec3TransformViaTempMtx((void *)(state + 6), (void *)(*state + 0xa0), vec);
    ScaleVec3Fx12(scale, (void *)(state + 6), (void *)(state + 6));
    if (*(unsigned char *)state[0x12] == 0) {
        short *pp = pair;
        void (*cb)();
        pp[1] = data_ov132_020d0d8c[1];
        pp[0] = data_ov132_020d0d8c[0];
        cb = *(void (**)())(*state + 0x24);
        if (cb != 0) cb(*state, pp, 4);
        Ov107_PostTagUpdate((Actor *)(*state), 10, 1);
        state[0x15] = 0;
        state[0xf] = 0x300;
        SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov132_HomingDash_Tick);
    }
}
