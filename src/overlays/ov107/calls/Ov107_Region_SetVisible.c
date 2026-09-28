typedef unsigned int u32;

typedef struct {
    int bit0 : 1;
    u32 pad : 31;
} Flags40;

typedef struct {
    u32 bit0 : 1;
    u32 flag2 : 1;
    u32 pad : 30;
} Flags5c;

typedef struct Inner2768 {
    char pad00[0x5c];
    Flags5c flags;
} Inner2768;

typedef struct Obj2768 {
    char pad00[0x40];
    Flags40 field_40;
    char pad44[0x104 - 0x44];
    Inner2768 *inner;
} Obj2768;

extern void invokeObjCallbackGuarded(int param_1);
extern int Node_CallHook80(char *p);
extern void Ov107_BroadcastValueToChildren(Obj2768 *self, int b);

void Ov107_Region_SetVisible(Obj2768 *self, int b)
{
    self->inner->flags.flag2 = (b == 0);

    if (b == 0)
        goto block2;

    if (self->field_40.bit0)
        goto block2;
    invokeObjCallbackGuarded((int)self->inner);
    goto end;

block2:
    if (b != 0)
        goto end;
    if (self->field_40.bit0)
        Node_CallHook80((char *)self->inner);

end:
    Ov107_BroadcastValueToChildren(self, b);
}
