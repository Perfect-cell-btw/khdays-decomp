/* Destructor: destroys the model (+0x384), the action resource (+0x390) and every part instance in
 * the table at +0x394, frees the table, then destroys the base object. */

#include "game/enemy_common.h"

extern void DestroyInstance();
extern void FreeInstanceMemory();
extern void Ov107_DestroyObject();

struct row8 { int a, b; };

void Ov195_ReleaseSubObjectsAndListThenNotify(int this_) {
    int i;
    DestroyInstance(*(int *)(this_ + 0x384));
    Ov107_ActionResource_Destroy((char *)(*(int *)(this_ + 0x3d0)));
    for (i = 0; i < 3; i++)
        DestroyInstance(((struct row8 *)*(int *)(this_ + 0x3d4))[i].a);
    FreeInstanceMemory(*(int *)(this_ + 0x3d4));
    Ov107_DestroyObject(this_);
}
