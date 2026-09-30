#include "game/engine.h"

extern int SetIndexedSlot();

/* The halfword at +0x60 is a bitfield pair; bit 0 of its low byte gates the step. */
struct Hw60_020ccf0c { unsigned short lo : 8; unsigned short hi : 8; };

void Ov137_PickRandomOffsetThenAdvanceSlot(unsigned char *obj) {
    unsigned char *mid = *(unsigned char **)(obj + 4);
    unsigned char *inner = *(unsigned char **)(mid + 0);
    if (((struct Hw60_020ccf0c *)(inner + 0x60))->lo & 1) {
        int base = *(int *)(inner + 0x224);
        int diff = *(int *)(inner + 0x228) - base;
        if (diff < 0) diff = -diff;
        *(int *)(mid + 0x44) = base + RandNextScaled(diff + 1);
        {
            unsigned char *in2 = *(unsigned char **)(mid + 0);
            *(signed char *)(in2 + 0x1c7) = *(signed char *)(in2 + 0x1c9);
        }
        SetIndexedSlot(obj, *(signed char *)(obj + 0x20), 0);
    }
}
