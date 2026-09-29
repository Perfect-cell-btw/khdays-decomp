/* Registers Ov251_CreateNamedEntity as the factory for entity class 0x4b. */

#include "game/enemy_common.h"

extern void Ov251_CreateNamedEntity(int);

void Ov251_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x4b, (void *)Ov251_CreateNamedEntity);
}
