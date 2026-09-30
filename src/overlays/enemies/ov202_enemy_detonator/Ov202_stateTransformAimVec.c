/* AI step: sets the velocity from the action resource's offset and scale in the actor's frame; once
 * the gate byte is clear sends the animation pair from the overlay's table to the actor's event
 * callback, posts pose 10, sets the dash speed and installs the homing-dash step. */

#include "game/engine.h"

extern int Ov107_ActionResource_GetOffsetAndScale(void *obj, int *vec);
extern void ScaleVec3Fx12(int scale, void *v, void *out);
extern void Ov107_PostTagUpdate();
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern unsigned short data_ov202_020cef64[];
extern void Ov202_HomingDashTick(void);

void Ov202_stateTransformAimVec(char *obj) {
    int *state = *(int **)(obj + 4);
    short pair[2];
    int vec[3];
    int scale;
    scale = Ov107_ActionResource_GetOffsetAndScale(*(void **)(*state + 0x388), vec);
    Vec3TransformViaTempMtx((void *)(state + 5), (void *)(*state + 0xa0), vec);
    ScaleVec3Fx12(scale, (void *)(state + 5), (void *)(state + 5));
    if (*(unsigned char *)state[0x11] == 0) {
        short *pp = pair;
        void (*cb)();
        pp[1] = data_ov202_020cef64[1];
        pp[0] = data_ov202_020cef64[0];
        cb = *(void (**)())(*state + 0x24);
        if (cb != 0) cb(*state, pp, 4);
        Ov107_PostTagUpdate(*state, 10, 1);
        state[0x14] = 0;
        state[0xe] = 0x300;
        SetIndexedSlot(obj, *(signed char *)(obj + 0x20), Ov202_HomingDashTick);
    }
}
