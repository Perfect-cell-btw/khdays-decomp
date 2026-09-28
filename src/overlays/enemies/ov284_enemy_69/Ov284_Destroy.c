extern void DestroyInstance();
extern void FreeInstanceMemory();
extern void Ov107_DestroyObject();

struct row8 { int a, b; };

void Ov284_Destroy(int this_) {
    int i;
    DestroyInstance(*(int *)(this_ + 0x384));
    DestroyInstance(*(int *)(this_ + 0x3ac));
    for (i = 0; i < 4; i++)
        DestroyInstance(((struct row8 *)*(int *)(this_ + 0x3b0))[i].a);
    FreeInstanceMemory(*(int *)(this_ + 0x3b0));
    Ov107_DestroyObject(this_);
}
