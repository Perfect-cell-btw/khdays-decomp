struct row8 { int a, b; };
extern void FreeInstanceMemory(int p);
extern void DestroyInstance(int p);
extern void Ov107_DestroyObject(int p);

void Ov157_DestroySubObjectsAndSlotsThenNotify(int this_) {
    int i;
    FreeInstanceMemory(*(int *)(this_ + 0x3a4));
    DestroyInstance(*(int *)(this_ + 0x384));
    for (i = 0; i < 4; i++) {
        DestroyInstance(((struct row8 *)(*(int *)(this_ + 0x3a0)))[i].a);
    }
    FreeInstanceMemory(*(int *)(this_ + 0x3a0));
    Ov107_DestroyObject(this_);
}
