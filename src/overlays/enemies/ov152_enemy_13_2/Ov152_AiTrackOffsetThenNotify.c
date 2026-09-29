/* Follows the owner-relative offset; when the watched flag clears sends the notify message and
 * queues action 2. */

#include "game/enemy_common.h"

extern void Vec3TransformViaTempMtx(void *dst, void *mtx, int *vec);
extern void ScaleVec3Fx12(int scale, void *v, void *out);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern unsigned short data_ov152_020d64b4[];

void Ov152_AiTrackOffsetThenNotify(char *obj) {
    int *state = *(int **)(obj + 4);
    short pair[2];
    int vec[3];
    int scale;
    scale = Ov107_ActionResource_GetOffsetAndScale((int)(*(void **)(*state + 0x3cc)), (VecFx32 *)vec);
    Vec3TransformViaTempMtx((void *)(state + 6), (void *)(*state + 0xa0), vec);
    ScaleVec3Fx12(scale, (void *)(state + 6), (void *)(state + 6));
    if (*(unsigned char *)state[0x12] == 0) {
        short *pp = pair;
        void (*cb)();
        pp[1] = data_ov152_020d64b4[1];
        pp[0] = data_ov152_020d64b4[0];
        cb = *(void (**)())(*state + 0x24);
        if (cb != 0) cb(*state, pp, 4);
        *(signed char *)(*state + 0x1c7) = 2;
        SetIndexedSlot(obj, *(signed char *)(obj + 0x20), (void *)0);
    }
}
