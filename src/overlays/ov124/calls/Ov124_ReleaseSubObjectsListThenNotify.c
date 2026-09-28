extern void DestroyInstance();
extern void FreeInstanceMemory();
extern void Ov107_DestroyObject();

struct row8 { int a, b; };

void Ov124_ReleaseSubObjectsListThenNotify(int this_) {
    int i;
    DestroyInstance(*(int *)(this_ + 0x384));
    for (i = 0; i < 2; i++)
        DestroyInstance(((struct row8 *)*(int *)(this_ + 0x398))[i].a);
    FreeInstanceMemory(*(int *)(this_ + 0x398));
    Ov107_DestroyObject(this_);
}
