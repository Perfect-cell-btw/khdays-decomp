/* Registers Ov153_CreateNamedEntity as the factory for entity class 0x14. */

#include "game/enemy_common.h"

extern void Ov153_CreateNamedEntity(int);

void Ov153_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x14, (void *)Ov153_CreateNamedEntity);
}
