/* Registers Ov166_CreateNamedEntity as the factory for entity class 0x1a. */

#include "game/enemy_common.h"

extern void Ov166_CreateNamedEntity(int);

void Ov166_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1a, (void *)Ov166_CreateNamedEntity);
}
