/* Registers Ov145_CreateNamedEntity as the factory for entity class 0xf. */

#include "game/enemy_common.h"

extern void Ov145_CreateNamedEntity(int);

void Ov145_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x0f, (void *)Ov145_CreateNamedEntity);
}
