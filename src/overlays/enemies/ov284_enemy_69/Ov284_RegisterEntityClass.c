/* Registers Ov284_CreateNamedEntity as the factory for entity class 0x69. */

#include "game/enemy_common.h"

extern void Ov284_CreateNamedEntity(int);

void Ov284_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x69, (void *)Ov284_CreateNamedEntity);
}
