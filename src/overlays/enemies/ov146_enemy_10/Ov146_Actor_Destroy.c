#include "game/enemy_common.h"

extern void FreeAllResourceTables(void *p);
extern void DestroyInstance(int handle);
extern void Ov107_DestroyObject(void *self);

/* Actor teardown: releases the resources this actor owns, then the shared base destructor. */
void Ov146_Actor_Destroy(char *self) {
    int i;
    FreeAllResourceTables(self + 0x388);
    DestroyInstance(*(int *)(self + 0x384));
    for (i = 0; i < 5; i++) {
        int h = *(int *)(self + i * sizeof(long long) + 0x3c4);
        if (h != 0) {
            DestroyInstance(h);
        }
    }
    Ov107_DestroyObject(self);
}
