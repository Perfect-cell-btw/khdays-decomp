/* Registers Ov192_CreateNamedEntity as the factory for enemy class 0x23 (Poison Plant) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov192_CreateNamedEntity(int);

void Ov192_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_POISON_PLANT, Ov192_CreateNamedEntity);
}
