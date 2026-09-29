/* Registers Ov124_CreateNamedEntity as the factory for entity class 0x5. */

#include "game/enemy_common.h"

extern void Ov124_CreateNamedEntity(int);

void Ov124_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x05, (void *)Ov124_CreateNamedEntity);
}
