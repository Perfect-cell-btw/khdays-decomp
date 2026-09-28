extern void FreeAllResourceTables(void *p);
extern void DestroyInstance(int handle);
extern void Ov107_ActionResource_Destroy(int handle);
extern void Ov107_DestroyObject(void *self);

/* Tears the actor down: both animation binders, the model and the effect handle, then the nine
 * attachment slots, and finally the shared base destructor. */
void Ov238_Actor_Destroy(char *self) {
    int i;
    FreeAllResourceTables(self + 0x394);
    FreeAllResourceTables(self + 0x3b8);
    DestroyInstance(*(int *)(self + 0x388));
    Ov107_ActionResource_Destroy(*(int *)(self + 0x3e0));
    for (i = 0; i < 9; i++) {
        DestroyInstance(*(int *)(self + i * sizeof(long long) + 0x404));
    }
    Ov107_DestroyObject(self);
}
