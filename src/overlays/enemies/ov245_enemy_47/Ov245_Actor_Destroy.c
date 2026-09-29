#include "game/enemy_common.h"

extern void FreeAllResourceTables(void *p);
extern void DestroyInstance(int handle);
extern void Ov107_DestroyObject(void *self);

/* Actor teardown: releases the resources this actor owns, then the shared base destructor. */

void Ov245_Actor_Destroy(char *self) {
    int i;
    int h;
    FreeAllResourceTables(self + 0x390);
    Ov107_ActionResource_Destroy((char *)(*(int *)(self + 0x4c8)));
    Ov107_ActionResource_Destroy((char *)(*(int *)(self + 0x4cc)));
    DestroyInstance(*(int *)(self + 0x384));
    for (i = 0; i < 2; i++) {
        DestroyInstance(*(int *)(self + i * sizeof(int) + 0x388));
    }
    h = *(int *)(self + 0x4dc);
    if (h != 0) {
        DestroyInstance(h);
    }
    Ov107_DestroyObject(self);
}
