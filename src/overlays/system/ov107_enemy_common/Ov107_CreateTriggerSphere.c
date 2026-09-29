/* Allocate a 0x44-byte object, initialise it (with this owner) via 020cb28c and return it. */

#include "game/enemy_common.h"

extern int CallocInstance(int a);
int Ov107_CreateTriggerSphere(int param_1) {
    int obj = CallocInstance(0x44);
    Ov107_TriggerSphere_Init(obj, param_1);
    return obj;
}
