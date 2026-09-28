/* Sets the locked stance flags (|0x86, bit 0 clear), shows the part, posts update 0x49, clears
 * pendingAction and ends the step. */

#include "game/actor.h"

extern int Ov107_BuildAndSendUpdate();
extern int SetIndexedSlot();

struct Inner2 {
    char _pad0[8];
    unsigned int bf8 : 8;      /* 0x08, bits [7:0] */
    unsigned int _bf8hi : 24;  /* 0x08, bits [31:8] */
};

struct Inner {
    Actor base;                  /* 0x000 */
    struct Inner2 *p38c;        /* 0x38c */
};

struct B {
    struct Inner *p0;          /* 0x00 */
    char _pad1[0x40 - 4];
    int f40;                   /* 0x40 */
};

struct A {
    char _pad0[4];
    struct B *f4;              /* 0x04 */
    char _pad1[0x20 - 8];
    signed char f20;           /* 0x20 */
};

void Ov203_AiEndWithUpdate(struct A *this)
{
    struct B *b = this->f4;

    b->p0->base.flags60.bits.hi &= ~1;
    b->p0->base.flags60.bits.hi |= (unsigned short)0x86;
    b->p0->p38c->bf8 &= ~1u;

    Ov107_BuildAndSendUpdate(b->p0, 0, 0x49, b->f40);

    b->p0->base.nextState = 0;
    SetIndexedSlot(this, this->f20, 0);
}
