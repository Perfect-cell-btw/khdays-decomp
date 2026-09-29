/* Dispatches the model's callbacks with the flag, or with the camera-distance LOD when not forced.
 */

#include "game/enemy_common.h"

extern void DispatchObjectCallbacks(int this_, int arg1);
extern int Ov107_IsBehindView(int ctx, void *extra);

typedef struct {
    char pad[0x5c];
    unsigned bit0 : 1;
    unsigned enableSomething : 1;
    unsigned rest : 30;
} Obj9c;

typedef struct {
    unsigned short lowFlags : 8;
    unsigned short highFlags : 8;
} Field60;

void Ov107_AiState_DispatchModelCallbacks(void *self_, int flag) {
    char *self = (char *)self_;
    Obj9c *t = *(Obj9c **)(self + 0x9c);
    Field60 *f60 = (Field60 *)(self + 0x60);

    if (t == 0) return;

    t->enableSomething = (f60->lowFlags & 0x80) != 0;

    if (flag != 0) {
        DispatchObjectCallbacks(*(int *)(self + 0x9c), flag);
        return;
    }

    if (f60->lowFlags & 0x20) {
        DispatchObjectCallbacks(*(int *)(self + 0x9c), flag);
        return;
    }

    {
        void *thr = func_ov107_020c9848();
        int ctx = *(int *)thr;
        int result = Ov107_IsBehindView(ctx, self + 0x74);
        DispatchObjectCallbacks(*(int *)(self + 0x9c), result);
    }
}
