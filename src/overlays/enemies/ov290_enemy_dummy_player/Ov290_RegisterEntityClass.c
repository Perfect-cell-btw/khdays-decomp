/* Registers Ov290_CreateNamedEntity as the factory for enemy class 0x6c (Dummy Player) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov290_CreateNamedEntity(int);

void Ov290_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_DUMMY_PLAYER, Ov290_CreateNamedEntity);
}
