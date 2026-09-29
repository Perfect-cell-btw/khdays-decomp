/* Registers Ov161_CreateNamedEntity as the factory for entity class 0x18. */

#include "game/enemy_common.h"

extern void Ov161_CreateNamedEntity(int);

void Ov161_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x18, (void *)Ov161_CreateNamedEntity);
}
