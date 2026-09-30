#include "game/actor.h"

int Ov284_ArbitrateSubStateEntry(int this_) {
    Actor *s = (Actor *)(**(int **)(this_ + 0x214));
    int cur = s->state;
    if (cur == 9) {
        s->nextState = 0;
        return 1;
    }
    if (s->nextState == 8 || cur == 8) {
        goto ret0;
    }
    if (s->contact17a.bits.bit0 == 0) {
        goto ret0;
    }
    if (cur == 2) {
        s->nextState = 8;
    }
ret0:
    return 0;
}
