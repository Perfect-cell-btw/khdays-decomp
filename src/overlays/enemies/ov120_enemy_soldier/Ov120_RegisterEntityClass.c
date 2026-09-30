/* Registers Ov120_CreateNamedEntity as the factory for enemy class 0x04 (Soldier) with the shared
 * enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov120_CreateNamedEntity(int);

void Ov120_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_SOLDIER, Ov120_CreateNamedEntity);
}
