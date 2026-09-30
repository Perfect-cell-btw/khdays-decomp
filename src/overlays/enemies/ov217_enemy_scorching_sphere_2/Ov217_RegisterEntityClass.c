/* Registers Ov217_AllocActorWithName as the factory for enemy class 0x2f (Scorching Sphere) with
 * the shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov217_AllocActorWithName(int);

void Ov217_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_SCORCHING_SPHERE, Ov217_AllocActorWithName);
}
