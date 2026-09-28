extern int DestroyInstance();
extern int FreeInstanceMemory();
extern int Ov107_DestroyObject();

struct S {
    char pad[0x384];
    int field_384;
    char pad2[0x390 - 0x384 - 4];
    int *field_390;
};

void Ov159_SubObject_Destroy(struct S *r0)
{
    DestroyInstance(r0->field_384);
    DestroyInstance(*r0->field_390);
    FreeInstanceMemory(r0->field_390);
    Ov107_DestroyObject(r0);
}
