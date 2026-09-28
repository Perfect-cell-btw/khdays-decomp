extern void FreeAllResourceTables(void *p);
extern void DestroyInstance(int handle);
extern void Ov107_ActionResource_Destroy(int handle);
extern void Ov107_DestroyObject(void *self);

/* Actor teardown: releases the resources this actor owns, then the shared base destructor. */

void Ov258_Actor_Destroy(char *self) {
    int i;
    FreeAllResourceTables(self + 0x388);
    *(int *)(self + 0x394) = 0;
    FreeAllResourceTables(self + 0x3b0);
    *(int *)(self + 0x3bc) = 0;
    DestroyInstance(*(int *)(self + 0x384));
    DestroyInstance(*(int *)(self + 0x3ac));
    for (i = 0; i < 0x2b; i++) {
        DestroyInstance(*(int *)(self + i * sizeof(long long) + 0x464));
    }
    Ov107_DestroyObject(self);
}
