/* Registers Ov167_CreateNamedEntity as the factory for entity class 0x1a. */

#include "game/enemy_common.h"

extern void Ov167_CreateNamedEntity(int);

void Ov167_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1a, (void *)Ov167_CreateNamedEntity);
}
