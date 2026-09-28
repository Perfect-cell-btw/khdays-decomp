extern void DestroyInstance(int handle);
extern void Ov107_ActionResource_Destroy(int handle);
extern void Ov107_DestroyObject(void *self);

/* Actor teardown: releases the resources this actor owns, then the shared base destructor. */
void Ov245_Actor3_Destroy(char *self) {
    int i;
    DestroyInstance(*(int *)(self + 0x384));
    Ov107_ActionResource_Destroy(*(int *)(self + 0x39c));
    for (i = 0; i < 3; i++) {
        DestroyInstance(*(int *)(self + i * sizeof(long long) + 0x3b4));
    }
    Ov107_DestroyObject(self);
}
