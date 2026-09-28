typedef struct { int w[4]; } Src4;
typedef struct { int w[3]; } Src3;

typedef struct {
    unsigned char type : 4;
    unsigned char kind : 4;
    char pad0[3];
    Src3 a;
    char pad1[0x58 - 0x10];
    Src4 b;
    Src4 c;
} Obj;

extern void *CallocInstance(unsigned int size);
extern void SrtTransform_SetIdentity(void *o);

void *Ov107_CloneResourceTransform(void *self)
{
    Obj *obj = (Obj *)CallocInstance(0x78);

    obj->type = 0;
    obj->kind |= 1;

    obj->b = *(Src4 *)self;
    obj->c = *(Src4 *)self;

    SrtTransform_SetIdentity((char *)obj + 0x10);

    obj->a = *(Src3 *)self;

    return obj;
}
