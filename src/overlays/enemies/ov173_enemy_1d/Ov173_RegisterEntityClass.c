/* Registers Ov173_CreateNamedEntity as the factory for entity class 0x1d. */

#include "game/enemy_common.h"

extern void Ov173_CreateNamedEntity(int);

void Ov173_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1d, (void *)Ov173_CreateNamedEntity);
}
