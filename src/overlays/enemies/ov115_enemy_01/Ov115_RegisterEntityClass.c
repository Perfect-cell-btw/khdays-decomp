/* Registers Ov115_CreateNamedEntity as the factory for entity class 0x1. */

#include "game/enemy_common.h"

extern void Ov115_CreateNamedEntity(int);

void Ov115_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x01, (void *)Ov115_CreateNamedEntity);
}
