/* Registers Ov171_CreateNamedEntity as the factory for entity class 0x1c. */

#include "game/enemy_common.h"

extern void Ov171_CreateNamedEntity(int);

void Ov171_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1c, (void *)Ov171_CreateNamedEntity);
}
