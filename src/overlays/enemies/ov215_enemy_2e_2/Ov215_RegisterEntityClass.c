/* Registers Ov215_AllocActorWithName as the factory for entity class 0x2e. */

#include "game/enemy_common.h"

extern void Ov215_AllocActorWithName(int);

void Ov215_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x2e, (void *)Ov215_AllocActorWithName);
}
