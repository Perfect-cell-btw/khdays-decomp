/* Registers Ov152_CreateNamedEntity as the factory for entity class 0x13. */

#include "game/enemy_common.h"

extern void Ov152_CreateNamedEntity(int);

void Ov152_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x13, (void *)Ov152_CreateNamedEntity);
}
