/* Registers Ov142_CreateNamedEntity as the factory for enemy class 0x0d (Loudmouth) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov142_CreateNamedEntity(int);

void Ov142_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_LOUDMOUTH, Ov142_CreateNamedEntity);
}
