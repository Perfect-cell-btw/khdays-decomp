/* Registers Ov176_CreateNamedEntity as the factory for entity class 0x1e. */

#include "game/enemy_common.h"

extern void Ov176_CreateNamedEntity(int);

void Ov176_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1e, (void *)Ov176_CreateNamedEntity);
}
