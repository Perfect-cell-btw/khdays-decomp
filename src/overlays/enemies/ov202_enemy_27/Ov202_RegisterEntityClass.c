/* Registers Ov202_AllocActorWithName as the factory for entity class 0x27. */

#include "game/enemy_common.h"

extern void Ov202_AllocActorWithName(int);

void Ov202_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x27, (void *)Ov202_AllocActorWithName);
}
