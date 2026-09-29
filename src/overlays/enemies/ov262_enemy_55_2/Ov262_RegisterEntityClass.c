/* Registers Ov262_CreateNamedEntity as the factory for entity class 0x55. */

#include "game/enemy_common.h"

extern void Ov262_CreateNamedEntity(int);

void Ov262_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x55, (void *)Ov262_CreateNamedEntity);
}
