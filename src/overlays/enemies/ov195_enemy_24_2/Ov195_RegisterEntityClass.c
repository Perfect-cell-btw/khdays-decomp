/* Registers Ov195_CreateNamedEntity as the factory for entity class 0x24. */

#include "game/enemy_common.h"

extern void Ov195_CreateNamedEntity(int);

void Ov195_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x24, (void *)Ov195_CreateNamedEntity);
}
