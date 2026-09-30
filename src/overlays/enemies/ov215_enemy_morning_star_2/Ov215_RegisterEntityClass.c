/* Registers Ov215_AllocActorWithName as the factory for enemy class 0x2e (Morning Star) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov215_AllocActorWithName(int);

void Ov215_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_MORNING_STAR, Ov215_AllocActorWithName);
}
