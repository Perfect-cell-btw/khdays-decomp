/* Transforms the offset through the owner's matrix and scales it; acts once the animation ends. */

#include "game/enemy_common.h"

extern void Vec3TransformViaTempMtx(void *dst, void *mtx, int *vec);
extern void ScaleVec3Fx12(int scale, void *v, void *out);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern unsigned short data_ov164_020d2c88[];
extern void Ov164_HomingDashTick(void);

void Ov164_AiTrackOffsetTick(char *obj) {
    int *state = *(int **)(obj + 4);
    short pair[2];
    int vec[3];
    int scale;
    scale = Ov107_ActionResource_GetOffsetAndScale((int)(*(void **)(*state + 0x3c8)), (VecFx32 *)vec);
    Vec3TransformViaTempMtx((void *)(state + 6), (void *)(*state + 0xa0), vec);
    ScaleVec3Fx12(scale, (void *)(state + 6), (void *)(state + 6));
    if (*(unsigned char *)state[0x16] == 0) {
        short *pp = pair;
        void (*cb)();
        pp[1] = data_ov164_020d2c88[1];
        pp[0] = data_ov164_020d2c88[0];
        cb = *(void (**)())(*state + 0x24);
        if (cb != 0) cb(*state, pp, 4);
        Ov107_PostTagUpdate((Actor *)(*state), 10, 1);
        state[0x19] = 0;
        state[0x13] = 0x300;
        SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov164_HomingDashTick);
    }
}
