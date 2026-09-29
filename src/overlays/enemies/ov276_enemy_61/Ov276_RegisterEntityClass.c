/* Registers Ov276_AllocActorWithName as the factory for entity class 0x61. */

#include "game/enemy_common.h"

extern void Ov276_AllocActorWithName(int);

void Ov276_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x61, (void *)Ov276_AllocActorWithName);
}
