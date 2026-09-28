extern int DestroyInstance();
extern int Ov107_ActionResource_Destroy();
extern int FreeInstanceMemory();
extern int Ov107_DestroyObject();

struct E {
    void *p;
    void *q;
};

struct S {
    char pad[0x384];
    void *p384;
    char pad2[0x3a0 - 0x388];
    void *p3a0;
    struct E *p3a4;
};

int Ov122_Destroy(struct S *r5) {
    int i;
    DestroyInstance(r5->p384);
    Ov107_ActionResource_Destroy(r5->p3a0);
    for (i = 0; i < 3; i++) {
        DestroyInstance(r5->p3a4[i].p);
    }
    FreeInstanceMemory(r5->p3a4);
    return Ov107_DestroyObject(r5);
}
