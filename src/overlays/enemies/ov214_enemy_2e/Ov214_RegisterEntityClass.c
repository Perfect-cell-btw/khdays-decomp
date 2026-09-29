/* Registers Ov214_AllocActorWithName as the factory for entity class 0x2e. */

#include "game/enemy_common.h"

extern void Ov214_AllocActorWithName(int);

void Ov214_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x2e, (void *)Ov214_AllocActorWithName);
}
