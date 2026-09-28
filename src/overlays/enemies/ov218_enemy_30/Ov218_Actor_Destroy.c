extern void DestroyInstance(int handle);
extern void Ov107_ActionResource_Destroy(int handle);
extern void Ov107_DestroyObject(void *self);

/* Actor teardown: releases the resources this actor owns, then the shared base destructor. */
void Ov218_Actor_Destroy(char *self) {
    int i;
    DestroyInstance(*(int *)(self + 0x384));
    Ov107_ActionResource_Destroy(*(int *)(self + 0x3ac));
    for (i = 0; i < 2; i++) {
        DestroyInstance(*(int *)(self + i * sizeof(long long) + 0x3dc));
    }
    Ov107_DestroyObject(self);
}
