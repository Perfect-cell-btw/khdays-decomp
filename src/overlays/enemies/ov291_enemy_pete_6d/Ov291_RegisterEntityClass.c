/* Registers Ov291_CreateNamedEntity as the factory for enemy class 0x6d (Pete) with the shared
 * enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov291_CreateNamedEntity(int);

void Ov291_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_PETE_6D, Ov291_CreateNamedEntity);
}
