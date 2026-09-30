/* Registers Ov114_CreateNamedEntity as the factory for enemy class 0x00 (Shadow) with the shared
 * enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov114_CreateNamedEntity(int);

void Ov114_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_SHADOW, Ov114_CreateNamedEntity);
}
