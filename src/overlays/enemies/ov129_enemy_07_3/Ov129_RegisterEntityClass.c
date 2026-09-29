/* Registers Ov129_CreateNamedEntity as the factory for entity class 0x7. */

#include "game/enemy_common.h"

extern void Ov129_CreateNamedEntity(int);

void Ov129_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x07, (void *)Ov129_CreateNamedEntity);
}
