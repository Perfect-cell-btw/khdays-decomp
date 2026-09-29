/* Registers Ov203_AllocActorWithName as the factory for entity class 0x27. */

#include "game/enemy_common.h"

extern void Ov203_AllocActorWithName(int);

void Ov203_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x27, (void *)Ov203_AllocActorWithName);
}
