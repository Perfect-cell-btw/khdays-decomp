/* Destroys the enemy: its models, its two part instances and the base object. */

extern void DestroyInstance();
extern void Ov107_DestroyObject();

struct row8 { int a, b; };

void Ov297_ReleaseSubObjectsAndSlotArrayThenNotify(int this_) {
    int i;
    DestroyInstance(*(int *)(this_ + 0x384));
    DestroyInstance(*(int *)(this_ + 0x388));
    for (i = 0; i < 2; i++)
        DestroyInstance(((struct row8 *)this_)[i + 115].a);
    Ov107_DestroyObject(this_);
}
