/* Host only: sends a member event of kind 2. */

#include "game/engine.h"

extern int data_ov022_020b2ea4;

struct marshal_0208a134 {
    unsigned char pad[4];
    unsigned char b012 : 3;
    unsigned char b345 : 3;
    unsigned char b67 : 2;
    unsigned char pad5;
};

void func_ov022_0208a134(int param_1) {
    struct marshal_0208a134 m;
    if (data_ov022_020b2ea4 == 0) {
        return;
    }
    if (Session_GetLocalPlayerIndex() != 0) {
        return;
    }
    m.b345 = param_1;
    m.b012 = 2;
    MsgQueue_Post(0xf, &m, 6);
}
