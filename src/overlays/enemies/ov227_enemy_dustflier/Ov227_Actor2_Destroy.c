#include "game/enemy_common.h"

extern void FreeAllResourceTables(void *p);
extern void DestroyInstance(int handle);
extern void Ov107_DestroyObject(void *self);

/* Actor teardown: releases the resources this actor owns, then the shared base destructor. */

void Ov227_Actor2_Destroy(char *self) {
    int i;
    FreeAllResourceTables(self + 0x388);
    *(int *)(self + 0x394) = 0;
    DestroyInstance(*(int *)(self + 0x384));
    Ov107_ActionResource_Destroy((char *)(*(int *)(self + 0x414)));
    for (i = 0; i < 8; i++) {
        int h = *(int *)(self + i * sizeof(long long) + 0x43c);
        if (h != 0) {
            DestroyInstance(h);
        }
    }
    Ov107_DestroyObject(self);
}
