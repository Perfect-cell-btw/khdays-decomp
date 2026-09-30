/* Registers Ov202_AllocActorWithName as the factory for enemy class 0x27 (Detonator) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov202_AllocActorWithName(int);

void Ov202_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_DETONATOR, Ov202_AllocActorWithName);
}
