/* Registers Ov296_CreateNamedEntity as the factory for entity class 0x70. */

#include "game/enemy_common.h"

extern void Ov296_CreateNamedEntity(int);

void Ov296_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x70, (void *)Ov296_CreateNamedEntity);
}
