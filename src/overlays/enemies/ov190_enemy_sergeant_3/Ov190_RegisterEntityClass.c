/* Registers Ov190_CreateNamedEntity as the factory for enemy class 0x22 (Sergeant) with the shared
 * enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov190_CreateNamedEntity(int);

void Ov190_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_SERGEANT, Ov190_CreateNamedEntity);
}
