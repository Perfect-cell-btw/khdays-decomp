/* Registers Ov269_CreateNamedEntity as the factory for entity class 0x5c. */

#include "game/enemy_common.h"

extern void Ov269_CreateNamedEntity(int);

void Ov269_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x5c, (void *)Ov269_CreateNamedEntity);
}
