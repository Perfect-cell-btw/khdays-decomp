/* Registers Ov241_CreateNamedEntity as the factory for entity class 0x44. */

#include "game/enemy_common.h"

extern void Ov241_CreateNamedEntity(int);

void Ov241_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x44, (void *)Ov241_CreateNamedEntity);
}
