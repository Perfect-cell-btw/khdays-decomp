/* Destructor: destroys the models, the action resource and the three part instances, frees the
 * waypoint table, then destroys the base object. */

extern void DestroyInstance(int p);
extern void Ov107_ActionResource_Destroy(int p);
extern void FreeInstanceMemory(int p);
extern void Ov107_DestroyObject(int p);

void Ov242_DestroyObjectsAndInlineArrayThenNotify(int this_) {
    int i;
    DestroyInstance(*(int *)(this_ + 0x384));
    Ov107_ActionResource_Destroy(*(int *)(this_ + 0x39c));
    DestroyInstance(*(int *)(this_ + 0x388));
    DestroyInstance(*(int *)(this_ + 0x3a0));
    for (i = 0; i < 3; i++) {
        DestroyInstance(((int *)this_)[0xe3 + i]);
    }
    if (*(int *)(this_ + 0x3a4) != 0) {
        FreeInstanceMemory(*(int *)(this_ + 0x3a4));
        *(int *)(this_ + 0x3a4) = 0;
    }
    Ov107_DestroyObject(this_);
}
