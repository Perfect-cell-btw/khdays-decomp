extern int FreeAllResourceTables();
extern int DestroyInstance();
extern int Ov107_ActionResource_Destroy();
extern int Ov107_DestroyObject();

struct E {
    void *p;
    void *q;
};

struct S {
    char pad[0x384];
    void *p384;
    char pad2[0x390 - 0x388];
    int n390;
    char pad3[0x3a8 - 0x394];
    void *p3a8;
    char pad4[0x490 - 0x3ac];
    void *p490;
    char pad5[0x4a8 - 0x494];
    struct E e4a8[10];
};

int Ov233_Destroy(struct S *r5) {
    int i;
    FreeAllResourceTables(&r5->p384);
    r5->n390 = 0;
    DestroyInstance(r5->p3a8);
    Ov107_ActionResource_Destroy(r5->p490);
    for (i = 0; i < 10; i++) {
        if (r5->e4a8[i].p) {
            DestroyInstance(r5->e4a8[i].p);
        }
    }
    return Ov107_DestroyObject(r5);
}
