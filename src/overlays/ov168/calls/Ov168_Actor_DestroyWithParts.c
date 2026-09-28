/* Destroys the model (+0x384) and the three part objects (+0x39c), frees the part array, runs
 * Ov107_DestroyObject. */

extern int DestroyInstance();
extern int FreeInstanceMemory();
extern int Ov107_DestroyObject();

struct Elem {
    int a;
    int b;
};

struct S {
    char pad[0x384];
    int field_384;
    char pad2[0x39c - 0x384 - 4];
    struct Elem *field_39c;
};

void Ov168_Actor_DestroyWithParts(struct S *s) {
    int i;
    DestroyInstance(s->field_384);
    for (i = 0; i < 3; i++) {
        DestroyInstance(s->field_39c[i].a);
    }
    FreeInstanceMemory(s->field_39c);
    Ov107_DestroyObject(s);
}
