extern void DestroyInstance(int handle);
extern void Ov107_ActionResource_Destroy(int handle);
extern void Ov107_DestroyObject(void *self);

/* Actor teardown: releases the resources this actor owns, then the shared base destructor. */
void Ov245_Actor2_Destroy(char *self) {
    int i;
    DestroyInstance(*(int *)(self + 0x384));
    for (i = 0; i < 3; i++) {
        int h = *(int *)(self + i * sizeof(long long) + 0x3e0);
        if (h != 0) {
            DestroyInstance(h);
        }
    }
    Ov107_DestroyObject(self);
}
