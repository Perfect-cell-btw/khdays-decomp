/* Registers Ov285_CreateNamedEntity as the factory for enemy class 0x6a (Creepworm) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov285_CreateNamedEntity(int);

void Ov285_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_CREEPWORM, Ov285_CreateNamedEntity);
}
