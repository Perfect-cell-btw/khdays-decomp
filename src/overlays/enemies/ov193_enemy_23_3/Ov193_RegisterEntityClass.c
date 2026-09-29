/* Registers Ov193_CreateNamedEntity as the factory for entity class 0x23. */

#include "game/enemy_common.h"

extern void Ov193_CreateNamedEntity(int);

void Ov193_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x23, (void *)Ov193_CreateNamedEntity);
}
