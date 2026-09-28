extern int DestroyInstance();
extern int FreeInstanceMemory();
extern int Ov107_DestroyObject();
extern int Ov107_ActionResource_Destroy();

struct E { int a; int b; };

void Ov250_Destroy(int *p) {
    int i;
    DestroyInstance(p[0x384 / 4]);
    Ov107_ActionResource_Destroy(p[0x390 / 4]);
    for (i = 0; i < 3; i++) {
        DestroyInstance(((struct E *)p[0x398 / 4])[i].a);
    }
    FreeInstanceMemory(p[0x398 / 4]);
    Ov107_DestroyObject(p);
}
