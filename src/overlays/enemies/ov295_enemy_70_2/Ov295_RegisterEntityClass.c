/* Registers Ov295_CreateNamedEntity as the factory for entity class 0x70. */

#include "game/enemy_common.h"

extern void Ov295_CreateNamedEntity(int);

void Ov295_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x70, (void *)Ov295_CreateNamedEntity);
}
