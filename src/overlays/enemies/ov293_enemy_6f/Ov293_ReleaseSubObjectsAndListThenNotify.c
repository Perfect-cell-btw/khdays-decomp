extern void DestroyInstance();
extern void Ov107_ActionResource_Destroy();
extern void FreeInstanceMemory();
extern void Ov107_DestroyObject();

struct row8 { int a, b; };

void Ov293_ReleaseSubObjectsAndListThenNotify(int this_) {
    int i;
    DestroyInstance(*(int *)(this_ + 0x384));
    Ov107_ActionResource_Destroy(*(int *)(this_ + 0x39c));
    for (i = 0; i < 2; i++)
        DestroyInstance(((struct row8 *)*(int *)(this_ + 0x3a0))[i].a);
    FreeInstanceMemory(*(int *)(this_ + 0x3a0));
    Ov107_DestroyObject(this_);
}
