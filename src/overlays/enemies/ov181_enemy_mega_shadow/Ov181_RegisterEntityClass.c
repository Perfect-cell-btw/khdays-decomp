/* Registers Ov181_CreateNamedEntity as the factory for enemy class 0x20 (Mega-Shadow) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov181_CreateNamedEntity(int);

void Ov181_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_MEGA_SHADOW, Ov181_CreateNamedEntity);
}
