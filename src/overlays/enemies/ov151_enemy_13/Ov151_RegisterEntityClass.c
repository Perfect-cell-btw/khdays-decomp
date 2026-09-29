/* Registers Ov151_CreateNamedEntity as the factory for entity class 0x13. */

#include "game/enemy_common.h"

extern void Ov151_CreateNamedEntity(int);

void Ov151_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x13, (void *)Ov151_CreateNamedEntity);
}
