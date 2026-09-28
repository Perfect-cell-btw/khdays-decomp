extern void DestroyInstance();
extern void Ov107_ActionResource_Destroy();
extern void FreeInstanceMemory();
extern void Ov107_DestroyObject();

struct row8 { int a, b; };

void Ov139_ReleaseSubObjectsAndListThenNotify(int this_) {
    int i;
    DestroyInstance(*(int *)(this_ + 0x384));
    Ov107_ActionResource_Destroy(*(int *)(this_ + 0x390));
    for (i = 0; i < 3; i++)
        DestroyInstance(((struct row8 *)*(int *)(this_ + 0x394))[i].a);
    FreeInstanceMemory(*(int *)(this_ + 0x394));
    Ov107_DestroyObject(this_);
}
