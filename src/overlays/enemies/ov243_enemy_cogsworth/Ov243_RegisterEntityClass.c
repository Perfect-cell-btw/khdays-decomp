/* Registers Ov243_CreateNamedEntity as the factory for enemy class 0x45 (Cogsworth) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov243_CreateNamedEntity(int);

void Ov243_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_COGSWORTH, Ov243_CreateNamedEntity);
}
