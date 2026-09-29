/* Registers Ov192_CreateNamedEntity as the factory for entity class 0x23. */

#include "game/enemy_common.h"

extern void Ov192_CreateNamedEntity(int);

void Ov192_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x23, (void *)Ov192_CreateNamedEntity);
}
