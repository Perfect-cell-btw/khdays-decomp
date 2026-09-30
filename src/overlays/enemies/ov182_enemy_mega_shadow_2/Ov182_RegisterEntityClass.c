/* Registers Ov182_CreateNamedEntity as the factory for enemy class 0x20 (Mega-Shadow) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov182_CreateNamedEntity(int);

void Ov182_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_MEGA_SHADOW, Ov182_CreateNamedEntity);
}
