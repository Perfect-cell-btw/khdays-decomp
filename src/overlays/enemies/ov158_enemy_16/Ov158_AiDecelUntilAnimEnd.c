/* Keeps the previous position and damps the velocity by 0xb00; once the animation ends queues
 * action 2 and ends the step. */

#include "game/actor.h"

extern int ScaleVec3Fx12();
extern int SetIndexedSlot();

struct Vec3 {
    unsigned int a, b, c;
};

struct Inner {
    Actor *p0;                /* +0x00 */
    unsigned char *p4;        /* +0x04 */
    char pad8[0x18 - 0x08];
    struct Vec3 dst;          /* +0x18 */
    struct Vec3 src;          /* +0x24 */
};

struct Obj {
    char pad0[4];
    struct Inner *inner;      /* +0x04 */
    char pad8[0x20 - 0x08];
    signed char b20;          /* +0x20 */
};

void Ov158_AiDecelUntilAnimEnd(struct Obj *o) {
    struct Inner *in = o->inner;
    Actor *q;

    in->dst = in->src;
    ScaleVec3Fx12(0xb00, &in->src, &in->src);

    if (in->p4[0xad] != 0)
        return;

    q = in->p0;
    if (q->contact17a.bits.bit0 == 0 && q->contact17c.bits.bit0 == 0)
        return;

    q->nextState = 2;
    SetIndexedSlot(o, (int)o->b20, 0);
}
