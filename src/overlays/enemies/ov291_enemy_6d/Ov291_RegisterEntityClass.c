/* Registers Ov291_CreateNamedEntity as the factory for entity class 0x6d. */

#include "game/enemy_common.h"

extern void Ov291_CreateNamedEntity(int);

void Ov291_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x6d, (void *)Ov291_CreateNamedEntity);
}
