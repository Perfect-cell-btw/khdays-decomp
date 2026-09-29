/* Registers Ov140_CreateNamedEntity as the factory for entity class 0xc. */

#include "game/enemy_common.h"

extern void Ov140_CreateNamedEntity(int);

void Ov140_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x0c, (void *)Ov140_CreateNamedEntity);
}
