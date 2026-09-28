typedef unsigned int u32;

typedef struct Obj {
    char pad0[0x94];
    void *field_94;
    char pad1[0x9c - 0x94 - 4];
    void *field_9c;
    void *field_a0;
    char pad2[0xb0 - 0xa4];
    void *field_b0;
} Obj;

extern void NNSi_FndDestroyDoubleList(void *list);
extern void FreeInstanceMemory(void *p);
extern void Ov107_Region_Destroy(Obj *self);

void Ov107_Scene_Destroy(Obj *self)
{
    if (self->field_b0) {
        NNSi_FndDestroyDoubleList(self->field_b0);
        FreeInstanceMemory(self->field_b0);
        self->field_b0 = 0;
    }
    if (self->field_94) {
        FreeInstanceMemory(self->field_94);
    }
    if (self->field_9c) {
        FreeInstanceMemory(self->field_9c);
    }
    if (self->field_a0) {
        FreeInstanceMemory(self->field_a0);
    }
    Ov107_Region_Destroy(self);
}
