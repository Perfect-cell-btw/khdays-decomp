/* Sends a gauge message (kind 0x10) with the actor, the local player and the value; stores the
 * message handle. */

#include "game/engine.h"

struct marshal_02094730 {
    unsigned char f0 : 2;
    unsigned char f2 : 3;
    unsigned char f5 : 3;
};

void func_ov022_02094730(int param_1, int param_2) {
    struct marshal_02094730 m;
    m.f0 = *(unsigned char *)(*(int *)(param_1 + 0x328) + 9);
    m.f2 = QueryActiveStateOrDelegate();
    m.f5 = param_2;
    *(short *)(param_1 + 0x33c) = MsgQueue_Post(0x10, &m, 1);
}
