#include "game/enemy_common.h"

extern void FreeAllResourceTables(void *p);
extern void DestroyInstance(int handle);
extern void Ov107_DestroyObject(void *self);

/* Actor teardown: the animation binder, the four models, the effect handle, then whichever of the
 * twelve attachment slots are actually occupied. */
void Ov260_Actor_Destroy(char *self) {
    int i;
    FreeAllResourceTables(self + 0x394);
    DestroyInstance(*(int *)(self + 0x384));
    DestroyInstance(*(int *)(self + 0x390));
    DestroyInstance(*(int *)(self + 0x388));
    DestroyInstance(*(int *)(self + 0x38c));
    Ov107_ActionResource_Destroy((char *)(*(int *)(self + 0x428)));
    for (i = 0; i < 0xc; i++) {
        int h = *(int *)(self + i * sizeof(long long) + 0x478);
        if (h != 0) {
            DestroyInstance(h);
        }
    }
    Ov107_DestroyObject(self);
}
