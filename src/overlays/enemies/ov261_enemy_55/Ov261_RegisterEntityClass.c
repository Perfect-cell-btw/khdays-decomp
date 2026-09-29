/* Registers Ov261_CreateNamedEntity as the factory for entity class 0x55. */

#include "game/enemy_common.h"

extern void Ov261_CreateNamedEntity(int);

void Ov261_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x55, (void *)Ov261_CreateNamedEntity);
}
