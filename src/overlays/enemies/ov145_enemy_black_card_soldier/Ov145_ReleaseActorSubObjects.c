/* Destructor: destroys the models, the action resource and the part instances, frees the path
 * table, then destroys the base object. */

#include "game/enemy_common.h"

extern void DestroyInstance();
extern void FreeInstanceMemory();
extern void Ov107_DestroyObject();

void Ov145_ReleaseActorSubObjects(int this_) {
    DestroyInstance(*(int *)(this_ + 0x384));
    Ov107_ActionResource_Destroy((char *)(*(int *)(this_ + 0x394)));
    DestroyInstance(*(int *)(this_ + 0x388));
    DestroyInstance(*(int *)(this_ + 0x398));
    DestroyInstance(*(int *)(this_ + 0x3f8));
    DestroyInstance(*(int *)(this_ + 0x38c));
    if (*(int *)(this_ + 0x39c) != 0) {
        FreeInstanceMemory(*(int *)(this_ + 0x39c));
        *(int *)(this_ + 0x39c) = 0;
    }
    Ov107_DestroyObject(this_);
}
