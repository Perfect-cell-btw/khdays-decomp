extern void DestroyInstance();
extern void Ov107_ActionResource_Destroy();
extern void Ov107_DestroyObject();

struct row8 { int a, b; };

void Ov189_ReleaseSubObjectsAndSlotArrayThenNotify(int this_) {
    int i;
    DestroyInstance(*(int *)(this_ + 0x384));
    Ov107_ActionResource_Destroy(*(int *)(this_ + 0x3c0));
    for (i = 0; i < 4; i++)
        DestroyInstance(((struct row8 *)this_)[i + 121].a);
    Ov107_DestroyObject(this_);
}
