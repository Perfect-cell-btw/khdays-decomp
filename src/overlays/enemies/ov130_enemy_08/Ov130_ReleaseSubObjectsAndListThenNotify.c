extern void DestroyInstance();
extern void Ov107_ActionResource_Destroy();
extern void FreeInstanceMemory();
extern void NNSi_FndDestroyDoubleList();
extern void Ov107_DestroyObject();

void Ov130_ReleaseSubObjectsAndListThenNotify(int this_) {
    DestroyInstance(*(int *)(this_ + 0x384));
    Ov107_ActionResource_Destroy(*(int *)(this_ + 0x390));
    DestroyInstance(*(int *)(*(int *)(this_ + 0x394)));
    FreeInstanceMemory(*(int *)(this_ + 0x394));
    NNSi_FndDestroyDoubleList(this_ + 0x398);
    Ov107_DestroyObject(this_);
}
