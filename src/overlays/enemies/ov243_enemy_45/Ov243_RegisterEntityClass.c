/* Registers Ov243_CreateNamedEntity as the factory for entity class 0x45. */

#include "game/enemy_common.h"

extern void Ov243_CreateNamedEntity(int);

void Ov243_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x45, (void *)Ov243_CreateNamedEntity);
}
