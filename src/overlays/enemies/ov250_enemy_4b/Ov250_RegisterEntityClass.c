/* Registers Ov250_CreateNamedEntity as the factory for entity class 0x4b. */

#include "game/enemy_common.h"

extern void Ov250_CreateNamedEntity(int);

void Ov250_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x4b, (void *)Ov250_CreateNamedEntity);
}
