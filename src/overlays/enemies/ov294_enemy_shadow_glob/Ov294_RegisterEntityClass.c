/* Registers Ov294_CreateNamedEntity as the factory for enemy class 0x70 (Shadow Glob) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov294_CreateNamedEntity(int);

void Ov294_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_SHADOW_GLOB, Ov294_CreateNamedEntity);
}
