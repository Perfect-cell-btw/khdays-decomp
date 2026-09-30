/* Registers Ov299_CreateNamedEntity as the factory for enemy class 0x73 (Turret) with the shared
 * enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov299_CreateNamedEntity(int);

void Ov299_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_TURRET, Ov299_CreateNamedEntity);
}
