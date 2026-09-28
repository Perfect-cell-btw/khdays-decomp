/* When the landing animation ends queues action 2, or action 6/7 at random once the counter ran
 * out. */

extern int RandNextScaled();
extern int SetIndexedSlot();

struct A { char pad0[4]; struct B *b; char pad8[0x20-8]; signed char field20; };
struct B { unsigned char *field0; struct C *field4; char pad8[0x44-8]; int field44; };
struct C { char pad[0xad]; unsigned char fieldAD; };

void Ov247_AiLandPickAction(struct A *a)
{
    struct B *b = a->b;
    int f44;

    if (b->field4->fieldAD != 0)
        return;

    f44 = b->field44;
    if (f44 <= 0) {
        if (RandNextScaled(2) + (f44 - f44) == 0)
            b->field0[0x1c7] = 7;
        else
            b->field0[0x1c7] = 6;
    } else {
        b->field0[0x1c7] = 2;
    }

    SetIndexedSlot(a, a->field20, 0);
}
