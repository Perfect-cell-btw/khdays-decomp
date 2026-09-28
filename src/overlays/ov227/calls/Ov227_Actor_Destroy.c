extern void DestroyInstance(int handle);
extern void Ov107_ActionResource_Destroy(int handle);
extern void Ov107_DestroyObject(void *self);

/* Actor teardown: releases the resources this actor owns, then the shared base destructor. */
void Ov227_Actor_Destroy(char *self) {
    int i;
    DestroyInstance(*(int *)(self + 0x384));
    for (i = 0; i < 2; i++) {
        int h = *(int *)(self + i * sizeof(long long) + 0x390);
        if (h != 0) {
            DestroyInstance(h);
        }
    }
    Ov107_DestroyObject(self);
}
