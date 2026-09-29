/* Transforms the offset through the owner's matrix and scales it; acts once the animation ends. */

#include "game/engine.h"

extern int Ov107_ActionResource_GetOffsetAndScale(void *obj, int *vec);
extern void ScaleVec3Fx12(int scale, void *v, void *out);
extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern unsigned short data_ov163_020d0e68[];
extern void Ov163_HomingDashTick(void);

void Ov163_AiTrackOffsetTick(char *obj) {
    int *state = *(int **)(obj + 4);
    short pair[2];
    int vec[3];
    int scale;
    scale = Ov107_ActionResource_GetOffsetAndScale(*(void **)(*state + 0x3c8), vec);
    Vec3TransformViaTempMtx((void *)(state + 6), (void *)(*state + 0xa0), vec);
    ScaleVec3Fx12(scale, (void *)(state + 6), (void *)(state + 6));
    if (*(unsigned char *)state[0x16] == 0) {
        short *pp = pair;
        void (*cb)();
        pp[1] = data_ov163_020d0e68[1];
        pp[0] = data_ov163_020d0e68[0];
        cb = *(void (**)())(*state + 0x24);
        if (cb != 0) cb(*state, pp, 4);
        Ov107_PostTagUpdate(*state, 10, 1);
        state[0x19] = 0;
        state[0x13] = 0x300;
        SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov163_HomingDashTick);
    }
}
