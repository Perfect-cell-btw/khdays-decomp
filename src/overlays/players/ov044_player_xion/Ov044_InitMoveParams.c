/* Sets the move parameters (speed 0xf46 in mode 1, else 0xa2f). */

#include "game/engine.h"

struct S {
    char pad0[0xc];
    int field_c;
    short field_10;
    char pad12[2];
    int field_14;
};

void Ov044_InitMoveParams(struct S *p) {
    p->field_c = 1;
    p->field_14 = 2;
    p->field_10 = (GetFrameRateMode() == 1) ? 0x0f46 : 0x0a2f;
}
