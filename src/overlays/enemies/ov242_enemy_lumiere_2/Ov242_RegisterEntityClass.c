/* Registers Ov242_CreateNamedEntity as the factory for enemy class 0x44 (Lumiere) with the shared
 * enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov242_CreateNamedEntity(int);

void Ov242_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_LUMIERE, Ov242_CreateNamedEntity);
}
