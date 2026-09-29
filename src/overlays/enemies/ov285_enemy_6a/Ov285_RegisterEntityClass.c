/* Registers Ov285_CreateNamedEntity as the factory for entity class 0x6a. */

#include "game/enemy_common.h"

extern void Ov285_CreateNamedEntity(int);

void Ov285_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x6a, (void *)Ov285_CreateNamedEntity);
}
