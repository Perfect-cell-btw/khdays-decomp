/* Registers Ov182_CreateNamedEntity as the factory for entity class 0x20. */

#include "game/enemy_common.h"

extern void Ov182_CreateNamedEntity(int);

void Ov182_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x20, (void *)Ov182_CreateNamedEntity);
}
