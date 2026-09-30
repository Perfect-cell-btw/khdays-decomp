/* Registers Ov189_CreateNamedEntity as the factory for enemy class 0x22 (Sergeant) with the shared
 * enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov189_CreateNamedEntity(int);

void Ov189_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_SERGEANT, Ov189_CreateNamedEntity);
}
