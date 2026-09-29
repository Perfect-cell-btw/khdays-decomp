/* Registers Ov288_CreateNamedEntity as the factory for entity class 0x6b. */

#include "game/enemy_common.h"

extern void Ov288_CreateNamedEntity(int);

void Ov288_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x6b, (void *)Ov288_CreateNamedEntity);
}
