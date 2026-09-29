/* Registers Ov191_CreateNamedEntity as the factory for entity class 0x23. */

#include "game/enemy_common.h"

extern void Ov191_CreateNamedEntity(int);

void Ov191_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x23, (void *)Ov191_CreateNamedEntity);
}
