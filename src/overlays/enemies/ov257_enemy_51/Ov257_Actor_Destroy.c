#include "game/enemy_common.h"

extern void FreeAllResourceTables(void *p);
extern void FreeInstanceMemory(void *p);
extern void DestroyInstance(int handle);
extern void Ov107_DestroyObject(void *self);

/* Actor teardown: releases the resources this actor owns, then the shared base destructor. */

void Ov257_Actor_Destroy(char *self) {
    int i;
    FreeAllResourceTables(*(void **)(self + 0x388));
    FreeInstanceMemory(*(void **)(self + 0x388));
    FreeAllResourceTables(*(void **)(self + 0x390));
    FreeInstanceMemory(*(void **)(self + 0x390));
    Ov107_ActionResource_Destroy((char *)(*(int *)(self + 0x3d0)));
    DestroyInstance(*(int *)(self + 0x384));
    DestroyInstance(*(int *)(self + 0x38c));
    for (i = 0; i < 4; i++) {
        DestroyInstance(*(int *)(self + i * sizeof(int) + 0x394));
    }
    for (i = 0; i < 4; i++) {
        DestroyInstance(*(int *)(self + i * sizeof(int) + 0x3a4));
    }
    for (i = 0; i < 0xc; i++) {
        DestroyInstance(*(int *)(*(char **)(self + 0x400) + i * sizeof(long long)));
    }
    FreeInstanceMemory(*(void **)(self + 0x400));
    Ov107_DestroyObject(self);
}
