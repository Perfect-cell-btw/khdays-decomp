#include "game/actor.h"

struct Mid {
    Actor *inner;
};

struct Obj {
    char pad[0x214];
    struct Mid *mid;
};

int Ov182_ReactionRequestSubState11(struct Obj *obj) {
    Actor *p = obj->mid->inner;
    int a = *((signed char *)p + 0x1c6);
    int b;
    if (a == 0xc) {
        *((signed char *)p + 0x1c7) = 0;
        return 1;
    }
    b = *((signed char *)p + 0x1c7);
    if (b != 0xb && a != 0xb && p->contact17a.bits.bit0) {
        if (!(a != 2 && a != 4 && a != 7 && a != 8))
            *((signed char *)p + 0x1c7) = 0xb;
    }
    return 0;
}
