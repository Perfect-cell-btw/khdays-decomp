/* Registers Ov141_CreateNamedEntity as the factory for entity class 0xd. */

#include "game/enemy_common.h"

extern void Ov141_CreateNamedEntity(int);

void Ov141_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x0d, (void *)Ov141_CreateNamedEntity);
}
