/* Registers Ov251_CreateNamedEntity as the factory for enemy class 0x4b (Gigas Shadow) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov251_CreateNamedEntity(int);

void Ov251_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_GIGAS_SHADOW, Ov251_CreateNamedEntity);
}
