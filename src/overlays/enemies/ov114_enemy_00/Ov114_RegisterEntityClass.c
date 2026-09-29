/* Registers Ov114_CreateNamedEntity as the factory for entity class 0x0. */

#include "game/enemy_common.h"

extern void Ov114_CreateNamedEntity(int);

void Ov114_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x00, (void *)Ov114_CreateNamedEntity);
}
