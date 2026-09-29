/* Registers Ov264_AllocActorWithName as the factory for entity class 0x58. */

#include "game/enemy_common.h"

extern void Ov264_AllocActorWithName(int);

void Ov264_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x58, (void *)Ov264_AllocActorWithName);
}
