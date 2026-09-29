/* Registers Ov128_CreateNamedEntity as the factory for entity class 0x7. */

#include "game/enemy_common.h"

extern void Ov128_CreateNamedEntity(int);

void Ov128_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x07, (void *)Ov128_CreateNamedEntity);
}
