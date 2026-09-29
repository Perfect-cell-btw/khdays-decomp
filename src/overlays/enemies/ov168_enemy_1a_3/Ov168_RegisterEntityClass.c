/* Registers Ov168_CreateNamedEntity as the factory for entity class 0x1a. */

#include "game/enemy_common.h"

extern void Ov168_CreateNamedEntity(int);

void Ov168_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1a, (void *)Ov168_CreateNamedEntity);
}
