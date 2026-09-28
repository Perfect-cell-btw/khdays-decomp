extern int SetIndexedSlot();
extern int Ov156_AiStep_QueueAction1IfActive();

struct Vec3 { int x, y, z; };
extern const struct Vec3 data_02041dc8;

struct D {
    char pad0[8];
    unsigned int f8 : 8;
};

struct C {
    char pad0[0x60];
    unsigned short f60;
    char pad62[0x326];
    struct D *f388;
};

struct B {
    struct C *p0;
    char pad4[8];
    struct Vec3 vc;
};

struct A {
    char pad0[4];
    struct B *b;
    char pad8[0x18];
    signed char f20;
};

void Ov156_ConfigHw60CopyVec3ConstToCThenAdvance(struct A *a)
{
    struct B *b = a->b;
    struct C *c;
    struct D *d;
    unsigned int x;

    c = b->p0;
    x = c->f60;
    c->f60 = (x & ~0xff00) |
             (((unsigned int)(unsigned short)(((x << 16) >> 24) & ~1) << 24) >> 16);

    c = b->p0;
    x = c->f60;
    c->f60 = (x & ~0xff00) | (((((x << 16) >> 24) | 0x82) << 24) >> 16);

    d = b->p0->f388;
    d->f8 = d->f8 & ~1;

    b->vc = data_02041dc8;

    SetIndexedSlot(a, a->f20, Ov156_AiStep_QueueAction1IfActive);
}
