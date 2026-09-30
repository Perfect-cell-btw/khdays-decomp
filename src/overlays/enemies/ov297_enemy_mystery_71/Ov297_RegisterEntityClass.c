/* Registers Ov297_CreateNamedEntity as the factory for enemy class 0x71 (the class shown as "? ? ?
 * ?") with the shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov297_CreateNamedEntity(int);

void Ov297_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_MYSTERY_71, Ov297_CreateNamedEntity);
}
