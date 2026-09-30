/* Destructor: destroys the model (+0x384), the second model (+0x388) and the trail instance
 * (+0x3f0), then the base object. */

extern void DestroyInstance();
extern void Ov107_DestroyObject();

void Ov197_ReleaseSubObjectsThenNotify(int this_) {
    DestroyInstance(*(int *)(this_ + 0x384));
    DestroyInstance(*(int *)(this_ + 0x388));
    DestroyInstance(*(int *)(this_ + 0x3f0));
    Ov107_DestroyObject(this_);
}
