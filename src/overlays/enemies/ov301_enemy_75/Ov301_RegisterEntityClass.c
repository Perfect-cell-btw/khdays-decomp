/* Registers Ov301_CreateNamedEntity as the factory for entity class 0x75. */

#include "game/enemy_common.h"

extern void Ov301_CreateNamedEntity(int);

void Ov301_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x75, (void *)Ov301_CreateNamedEntity);
}
