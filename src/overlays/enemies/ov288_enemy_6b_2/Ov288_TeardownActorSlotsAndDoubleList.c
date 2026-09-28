/* Destructor: destroys the model (+0x384) and the two part instances that exist, destroys the list
 * at +0x398, then the base object. */

extern void DestroyInstance();
extern void NNSi_FndDestroyDoubleList();
extern void Ov107_DestroyObject();

struct row8 { int a, b; };

void Ov288_TeardownActorSlotsAndDoubleList(int this_) {
    int i;
    DestroyInstance(*(int *)(this_ + 0x384));
    for (i = 0; i < 2; i++) {
        int slot = ((struct row8 *)this_)[i + 120].a;
        if (slot) DestroyInstance(slot);
    }
    NNSi_FndDestroyDoubleList(this_ + 0x398);
    Ov107_DestroyObject(this_);
}
