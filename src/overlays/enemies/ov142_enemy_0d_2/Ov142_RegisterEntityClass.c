/* Registers Ov142_CreateNamedEntity as the factory for entity class 0xd. */

#include "game/enemy_common.h"

extern void Ov142_CreateNamedEntity(int);

void Ov142_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x0d, (void *)Ov142_CreateNamedEntity);
}
