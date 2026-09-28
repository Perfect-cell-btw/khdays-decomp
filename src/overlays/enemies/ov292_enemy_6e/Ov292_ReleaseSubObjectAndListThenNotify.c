/* Destroys the enemy: its model, its list and the base object. */

extern void DestroyInstance();
extern void NNSi_FndDestroyDoubleList();
extern void Ov107_DestroyObject();

void Ov292_ReleaseSubObjectAndListThenNotify(int this_) {
    DestroyInstance(*(int *)(this_ + 0x384));
    NNSi_FndDestroyDoubleList(this_ + 0x394);
    Ov107_DestroyObject(this_);
}
