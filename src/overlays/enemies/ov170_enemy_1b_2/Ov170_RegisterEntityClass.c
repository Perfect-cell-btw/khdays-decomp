/* Registers Ov170_CreateNamedEntity as the factory for entity class 0x1b. */

#include "game/enemy_common.h"

extern void Ov170_CreateNamedEntity(int);

void Ov170_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1b, (void *)Ov170_CreateNamedEntity);
}
