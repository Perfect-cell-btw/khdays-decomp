extern void DestroyInstance();
extern void Ov107_DestroyObject();

void Ov298_ReleaseSubObjectsThenNotify(int this_) {
    DestroyInstance(*(int *)(this_ + 0x384));
    DestroyInstance(*(int *)(this_ + 0x388));
    DestroyInstance(*(int *)(this_ + 0x39c));
    Ov107_DestroyObject(this_);
}
