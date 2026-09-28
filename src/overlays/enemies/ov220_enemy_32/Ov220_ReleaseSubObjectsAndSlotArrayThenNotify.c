extern void DestroyInstance();
extern void Ov107_ActionResource_Destroy();
extern void Ov107_DestroyObject();

struct row8 { int a, b; };

void Ov220_ReleaseSubObjectsAndSlotArrayThenNotify(int this_) {
    int i;
    DestroyInstance(*(int *)(this_ + 0x384));
    Ov107_ActionResource_Destroy(*(int *)(this_ + 0x394));
    for (i = 0; i < 3; i++)
        DestroyInstance(((struct row8 *)this_)[i + 120].b);
    Ov107_DestroyObject(this_);
}
