/* Registers Ov300_CreateNamedEntity as the factory for enemy class 0x74 (Device) with the shared
 * enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov300_CreateNamedEntity(int);

void Ov300_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_DEVICE, Ov300_CreateNamedEntity);
}
