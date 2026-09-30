/* Registers Ov124_CreateNamedEntity as the factory for enemy class 0x05 (Dire Plant) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov124_CreateNamedEntity(int);

void Ov124_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_DIRE_PLANT, Ov124_CreateNamedEntity);
}
