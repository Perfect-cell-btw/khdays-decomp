/* Registers Ov296_CreateNamedEntity as the factory for enemy class 0x70 (Shadow Glob) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov296_CreateNamedEntity(int);

void Ov296_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_SHADOW_GLOB, Ov296_CreateNamedEntity);
}
