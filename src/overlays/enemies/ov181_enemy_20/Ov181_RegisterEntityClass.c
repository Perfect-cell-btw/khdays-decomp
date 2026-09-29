/* Registers Ov181_CreateNamedEntity as the factory for entity class 0x20. */

#include "game/enemy_common.h"

extern void Ov181_CreateNamedEntity(int);

void Ov181_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x20, (void *)Ov181_CreateNamedEntity);
}
