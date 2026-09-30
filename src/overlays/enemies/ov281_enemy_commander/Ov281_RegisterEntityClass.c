/* Registers Ov281_CreateNamedEntity as the factory for enemy class 0x66 (Commander) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov281_CreateNamedEntity(int);

void Ov281_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_COMMANDER, Ov281_CreateNamedEntity);
}
