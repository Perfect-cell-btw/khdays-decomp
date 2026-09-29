/* Registers Ov130_CreateNamedEntity as the factory for entity class 0x8. */

#include "game/enemy_common.h"

extern void Ov130_CreateNamedEntity(int);

void Ov130_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x08, (void *)Ov130_CreateNamedEntity);
}
