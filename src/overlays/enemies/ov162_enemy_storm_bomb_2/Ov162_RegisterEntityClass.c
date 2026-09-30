/* Registers Ov162_CreateNamedEntity as the factory for enemy class 0x18 (Storm Bomb) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov162_CreateNamedEntity(int);

void Ov162_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_STORM_BOMB, Ov162_CreateNamedEntity);
}
