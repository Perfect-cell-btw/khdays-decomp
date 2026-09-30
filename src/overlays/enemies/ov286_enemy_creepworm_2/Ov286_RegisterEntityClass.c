/* Registers Ov286_CreateNamedEntity as the factory for enemy class 0x6a (Creepworm) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov286_CreateNamedEntity(int);

void Ov286_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_CREEPWORM, Ov286_CreateNamedEntity);
}
