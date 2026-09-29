/* Registers Ov155_CreateNamedEntity as the factory for entity class 0x14. */

#include "game/enemy_common.h"

extern void Ov155_CreateNamedEntity(int);

void Ov155_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x14, (void *)Ov155_CreateNamedEntity);
}
