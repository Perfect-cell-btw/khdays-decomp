/* Registers Ov204_CreateNamedEntity as the factory for entity class 0x28. */

#include "game/enemy_common.h"

extern void Ov204_CreateNamedEntity(int);

void Ov204_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x28, (void *)Ov204_CreateNamedEntity);
}
