/* Registers Ov234_CreateNamedEntity as the factory for entity class 0x3d. */

#include "game/enemy_common.h"

extern void Ov234_CreateNamedEntity(int);

void Ov234_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x3d, (void *)Ov234_CreateNamedEntity);
}
