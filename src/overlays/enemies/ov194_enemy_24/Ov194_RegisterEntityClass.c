/* Registers Ov194_CreateNamedEntity as the factory for entity class 0x24. */

#include "game/enemy_common.h"

extern void Ov194_CreateNamedEntity(int);

void Ov194_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x24, (void *)Ov194_CreateNamedEntity);
}
