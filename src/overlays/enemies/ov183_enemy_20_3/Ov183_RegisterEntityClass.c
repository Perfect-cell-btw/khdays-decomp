/* Registers Ov183_CreateNamedEntity as the factory for entity class 0x20. */

#include "game/enemy_common.h"

extern void Ov183_CreateNamedEntity(int);

void Ov183_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x20, (void *)Ov183_CreateNamedEntity);
}
