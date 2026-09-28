extern int DestroyInstance();
extern int FreeInstanceMemory();
extern int Ov107_DestroyObject();

struct Elem {
    void *ptr;
    void *other;
};

struct S {
    char pad[0x384];
    void *p384;
    char pad2[0x394 - 0x388];
    struct Elem *p394;
};

int Ov244_Destroy(struct S *r5) {
    int i;
    DestroyInstance(r5->p384);
    for (i = 0; i < 2; i++) {
        DestroyInstance(r5->p394[i].ptr);
    }
    FreeInstanceMemory(r5->p394);
    return Ov107_DestroyObject(r5);
}
