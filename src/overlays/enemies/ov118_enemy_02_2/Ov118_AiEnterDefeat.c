/* AI step: enters defeat: sets the defeat bits in the high byte of the actor's flags (+0x60) and
 * bit 0 of +0x1ae, clears bit 0 of its model's flag byte and clears the step handler. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int SetIndexedSlot();

union F {
    u16 w;
    struct {
        u16 lo : 8;
        u16 hi : 8;
    } bf;
};

struct D {
    char pad0[8];
    unsigned int f8 : 8;
};

struct C {
    char pad0[0x60];
    union F f60;
    char pad62[0x14c];
    unsigned short f1ae;
    char pad1b0[0x1d8];
    struct D *f388;
};

struct B {
    struct C *p0;
};

struct A {
    char pad0[4];
    struct B *b;
    char pad8[0x18];
    signed char f20;
};

void Ov118_AiEnterDefeat(struct A *a)
{
    struct B *b = a->b;
    struct D *d;

    b->p0->f60.w = (u16)((b->p0->f60.w & ~0xff00) | (((b->p0->f60.bf.hi | 0xce) & 0xff) << 8));

    b->p0->f1ae = b->p0->f1ae | 1;

    d = b->p0->f388;
    d->f8 = d->f8 & ~1;

    SetIndexedSlot(a, a->f20, 0);
}
