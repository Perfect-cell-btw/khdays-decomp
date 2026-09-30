/* Destructor: destroys the model (+0x384) and the three part instances, then the base object. */

extern void DestroyInstance();
extern void Ov107_DestroyObject();

struct row8 { int a, b; };

void Ov245_ReleaseSubObjectsLoopThenNotify(int this_) {
    int i;
    DestroyInstance(*(int *)(this_ + 0x384));
    for (i = 0; i < 3; i++) {
        DestroyInstance(((struct row8 *)this_)[i + 114].b);
    }
    Ov107_DestroyObject(this_);
}
