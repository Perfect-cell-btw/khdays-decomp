/* Registers Ov197_CreateNamedEntity as the factory for entity class 0x25. */

#include "game/enemy_common.h"

extern void Ov197_CreateNamedEntity(int);

void Ov197_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x25, (void *)Ov197_CreateNamedEntity);
}
