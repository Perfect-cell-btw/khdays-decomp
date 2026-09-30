/* Registers Ov121_CreateNamedEntity as the factory for enemy class 0x04 (Soldier) with the shared
 * enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov121_CreateNamedEntity(int);

void Ov121_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_SOLDIER, Ov121_CreateNamedEntity);
}
