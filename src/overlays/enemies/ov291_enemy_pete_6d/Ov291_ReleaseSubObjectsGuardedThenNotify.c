/* Destroys the enemy: frees its path data, destroys its models and action resource, and the base
 * object. */

#include "game/enemy_common.h"

extern void FreeInstanceMemory();
extern void DestroyInstance();
extern void Ov107_DestroyObject();

void Ov291_ReleaseSubObjectsGuardedThenNotify(int this_) {
    if (*(int *)(this_ + 0x3a0) != 0) {
        FreeInstanceMemory(*(int *)(this_ + 0x3a0));
    }
    DestroyInstance(*(int *)(this_ + 0x384));
    Ov107_ActionResource_Destroy((char *)(*(int *)(this_ + 0x394)));
    DestroyInstance(*(int *)(this_ + 0x388));
    DestroyInstance(*(int *)(this_ + 0x398));
    Ov107_DestroyObject(this_);
}
