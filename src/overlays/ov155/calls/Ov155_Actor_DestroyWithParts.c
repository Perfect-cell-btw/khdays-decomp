/* Destroys the model (+0x384) and both part objects (+0x390), frees the part array and runs
 * Ov107_DestroyObject. */

extern int DestroyInstance();
extern int FreeInstanceMemory();
extern int Ov107_DestroyObject();

struct Elem {
    void *ptr;
    int other;
};

struct S {
    char pad[0x384];
    void *m384;
    char pad2[0x390 - 0x388];
    struct Elem *m390;
};

int Ov155_Actor_DestroyWithParts(struct S *r5) {
    int i;
    DestroyInstance(r5->m384);
    for (i = 0; i < 2; i++) {
        DestroyInstance(r5->m390[i].ptr);
    }
    FreeInstanceMemory(r5->m390);
    return Ov107_DestroyObject(r5);
}
