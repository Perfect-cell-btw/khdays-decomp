/* Registers Ov216_AllocActorWithName as the factory for entity class 0x2f. */

#include "game/enemy_common.h"

extern void Ov216_AllocActorWithName(int);

void Ov216_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x2f, (void *)Ov216_AllocActorWithName);
}
