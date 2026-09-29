/* Teardown: destroy primary sub-object (0x384), destroy sub-list (0x3cc via
 * Ov107_ActionResource_Destroy), destroy 5-entry object array (0x390), free array + 0x3c8 buffer
 * via FreeInstanceMemory, then notify parent (Ov107_DestroyObject). */

#include "game/enemy_common.h"

struct row8 { int a, b; };
extern void DestroyInstance(int p);
extern void FreeInstanceMemory(int p);
extern void Ov107_DestroyObject(int p);

void Ov152_DestroySubListAndArraySlotsThenNotify(int this_) {
    int i;
    DestroyInstance(*(int *)(this_ + 0x384));
    Ov107_ActionResource_Destroy((char *)(*(int *)(this_ + 0x3cc)));
    for (i = 0; i < 5; i++) {
        DestroyInstance(((struct row8 *)(*(int *)(this_ + 0x390)))[i].a);
    }
    FreeInstanceMemory(*(int *)(this_ + 0x390));
    FreeInstanceMemory(*(int *)(this_ + 0x3c8));
    Ov107_DestroyObject(this_);
}
