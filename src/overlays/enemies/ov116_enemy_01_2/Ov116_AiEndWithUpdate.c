/* Sets the stance flags (hi byte bit 0 clear, |6 |0x80), +0x1ae |= 3, clears child +0x388 bit 0,
 * posts an update, clears pendingAction and ends the AI task. */

extern int Ov107_BuildAndSendUpdate();
extern int SetIndexedSlot();

struct D {
    char pad0[8];
    unsigned int f8 : 8;
};

struct C {
    char pad0[0x60];
    unsigned short : 8;
    unsigned short hi : 8;
    char pad62[0x14c];
    unsigned short f1ae;
    char pad1b0[0x1d8];
    struct D *f388;
};

struct B {
    struct C *p0;
    char pad4[4];
    int f8;
};

struct A {
    char pad0[4];
    struct B *b;
    char pad8[0x18];
    signed char f20;
};

void Ov116_AiEndWithUpdate(struct A *a)
{
    struct B *b = a->b;
    struct D *d;
    unsigned short v6 = 6;
    unsigned short v80 = 0x80;

    b->p0->hi = b->p0->hi & ~1;

    b->p0->hi |= v6;

    b->p0->f1ae = b->p0->f1ae | 3;

    d = b->p0->f388;
    d->f8 = d->f8 & ~1;

    b->p0->hi |= v80;

    Ov107_BuildAndSendUpdate(b->p0, 0, 0x4a, b->f8);

    ((unsigned char *)b->p0)[0x1c7] = 0;

    SetIndexedSlot(a, a->f20, 0);
}
