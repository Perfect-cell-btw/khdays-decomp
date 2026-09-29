/* Registers Ov132_CreateNamedEntity as the factory for entity class 0x9. */

#include "game/enemy_common.h"

extern void Ov132_CreateNamedEntity(int);

void Ov132_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x09, (void *)Ov132_CreateNamedEntity);
}
