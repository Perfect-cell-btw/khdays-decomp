/* Registers Ov153_CreateNamedEntity as the factory for enemy class 0x14 (Fire Plant) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov153_CreateNamedEntity(int);

void Ov153_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_FIRE_PLANT, Ov153_CreateNamedEntity);
}
