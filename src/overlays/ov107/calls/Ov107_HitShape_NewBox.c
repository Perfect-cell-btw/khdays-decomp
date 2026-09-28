/* Allocates a 0xd0-byte box hit shape from the basis (identity transform). */

typedef struct { int w[15]; } Basis;
typedef struct { int w[3]; } Src3;

typedef struct {
    unsigned char type : 4;
    unsigned char kind : 4;
    char pad0[3];
    Src3 a;
    char pad1[0x58 - 0x10];
    Basis b;
    Basis c;
} Obj;

extern void *CallocInstance(unsigned int size);
extern void SrtTransform_SetIdentity(void *o);

void *Ov107_HitShape_NewBox(Basis *self)
{
    Obj *obj = (Obj *)CallocInstance(0xd0);

    obj->type = 2;
    obj->kind |= 1;

    obj->b = *self;
    obj->c = *self;

    SrtTransform_SetIdentity((char *)obj + 0x10);

    obj->a = *(Src3 *)self;

    return obj;
}
