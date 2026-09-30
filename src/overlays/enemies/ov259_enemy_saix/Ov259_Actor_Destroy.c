#include "game/enemy_common.h"

extern void FreeAllResourceTables(void *p);
extern void DestroyInstance(int handle);
extern void Ov107_DestroyObject(void *self);

/* Actor teardown: releases the resources this actor owns, then the shared base destructor. */

void Ov259_Actor_Destroy(char *self) {
    int i;
    char *binder = self + 0x398;
    char *slot = self;
    for (i = 0; i < 2; i++) {
        FreeAllResourceTables(binder);
        *(int *)(slot + 0x3a4) = 0;
        binder += 0x24;
        slot += 0x24;
    }
    FreeAllResourceTables(self + 0x3e0);
    *(int *)(self + 0x3ec) = 0;
    DestroyInstance(*(int *)(self + 0x38c));
    DestroyInstance(*(int *)(self + 0x390));
    Ov107_ActionResource_Destroy((char *)(*(int *)(self + 0x414)));
    for (i = 0; i < 0xd; i++) {
        DestroyInstance(*(int *)(self + i * sizeof(long long) + 0x430));
    }
    Ov107_DestroyObject(self);
}
