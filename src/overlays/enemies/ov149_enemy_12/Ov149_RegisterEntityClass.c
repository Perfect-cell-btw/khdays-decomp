/* Registers Ov149_CreateNamedEntity as the factory for entity class 0x12. */

#include "game/enemy_common.h"

extern void Ov149_CreateNamedEntity(int);

void Ov149_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x12, (void *)Ov149_CreateNamedEntity);
}
