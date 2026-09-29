/* Registers Ov217_AllocActorWithName as the factory for entity class 0x2f. */

#include "game/enemy_common.h"

extern void Ov217_AllocActorWithName(int);

void Ov217_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x2f, (void *)Ov217_AllocActorWithName);
}
