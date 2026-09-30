/* Destructor: destroys the model (+0x384), the action resource (+0x390) and the part instance with
 * its table (+0x394), destroys the list at +0x398, then the base object. */

#include "game/enemy_common.h"

extern void DestroyInstance();
extern void FreeInstanceMemory();
extern void NNSi_FndDestroyDoubleList();
extern void Ov107_DestroyObject();

void Ov130_ReleaseSubObjectsAndListThenNotify(int this_) {
    DestroyInstance(*(int *)(this_ + 0x384));
    Ov107_ActionResource_Destroy((char *)(*(int *)(this_ + 0x390)));
    DestroyInstance(*(int *)(*(int *)(this_ + 0x394)));
    FreeInstanceMemory(*(int *)(this_ + 0x394));
    NNSi_FndDestroyDoubleList(this_ + 0x398);
    Ov107_DestroyObject(this_);
}
