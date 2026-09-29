/* Release the sub-resource at +0x190, then tear down the object. */

#include "game/enemy_common.h"

extern void DestroyInstance(int arg);
void Ov282_Destroy_2(int param_1) {
    DestroyInstance(*(int *)(param_1 + 0x190));
    Ov107_DestroyNode((char *)param_1);
}
