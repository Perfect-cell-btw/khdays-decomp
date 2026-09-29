/* Registers Ov294_CreateNamedEntity as the factory for entity class 0x70. */

#include "game/enemy_common.h"

extern void Ov294_CreateNamedEntity(int);

void Ov294_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x70, (void *)Ov294_CreateNamedEntity);
}
