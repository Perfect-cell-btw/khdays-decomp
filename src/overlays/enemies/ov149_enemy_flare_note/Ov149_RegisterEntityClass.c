/* Registers Ov149_CreateNamedEntity as the factory for enemy class 0x12 (Flare Note) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov149_CreateNamedEntity(int);

void Ov149_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_FLARE_NOTE, Ov149_CreateNamedEntity);
}
