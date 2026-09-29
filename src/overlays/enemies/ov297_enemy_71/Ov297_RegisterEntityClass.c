/* Registers Ov297_CreateNamedEntity as the factory for entity class 0x71. */

#include "game/enemy_common.h"

extern void Ov297_CreateNamedEntity(int);

void Ov297_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x71, (void *)Ov297_CreateNamedEntity);
}
