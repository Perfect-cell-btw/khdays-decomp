extern void FreeAllResourceTables(void *p);
extern void FreeInstanceMemory(void *p);
extern void DestroyInstance(int handle);
extern void Ov107_ActionResource_Destroy(int handle);
extern void Ov107_DestroyObject(void *self);

/* Actor teardown: releases the resources this actor owns, then the shared base destructor. */

void Ov252_Actor_Destroy(char *self) {
    int i;
    char *binder = self + 0x3a0;
    char *slot = self;
    char *binder2;
    char *slot2;
    for (i = 0; i < 4; i++) {
        FreeAllResourceTables(binder);
        *(int *)(slot + 0x3ac) = 0;
        binder += 0x24;
        slot += 0x24;
    }
    FreeAllResourceTables(self + 0x430);
    *(int *)(self + 0x43c) = 0;
    binder2 = self + 0x454;
    slot2 = self;
    for (i = 0; i < 4; i++) {
        FreeAllResourceTables(binder2);
        *(int *)(slot2 + 0x460) = 0;
        binder2 += 0x24;
        slot2 += 0x24;
    }
    Ov107_ActionResource_Destroy(*(int *)(self + 0x574));
    DestroyInstance(*(int *)(self + 0x384));
    DestroyInstance(*(int *)(self + 0x388));
    for (i = 0; i < 4; i++) {
        DestroyInstance(*(int *)(self + i * sizeof(int) + 0x38c));
    }
    for (i = 0; i < 0x31; i++) {
        DestroyInstance(*(int *)(self + i * sizeof(long long) + 0x63c));
    }
    Ov107_DestroyObject(self);
}
