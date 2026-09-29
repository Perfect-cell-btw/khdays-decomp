/* Releases the eight emitter objects' sequences. */

#include "game/engine.h"

void Ov063_ReleaseChildArray8(char *obj) {
    int i = 0;
    char *p = obj + 0x234;
    for (; i < 8; i++) {
        ReleaseField74AndCleanup(p);
        p += 0x170;
    }
}
