/* Registers Ov184_CreateNamedEntity as the factory for entity class 0x20. */

#include "game/enemy_common.h"

extern void Ov184_CreateNamedEntity(int);

void Ov184_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x20, (void *)Ov184_CreateNamedEntity);
}
