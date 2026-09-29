/* Registers Ov172_CreateNamedEntity as the factory for entity class 0x1c. */

#include "game/enemy_common.h"

extern void Ov172_CreateNamedEntity(int);

void Ov172_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1c, (void *)Ov172_CreateNamedEntity);
}
