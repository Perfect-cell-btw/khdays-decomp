/* Registers Ov289_CreateNamedEntity as the factory for entity class 0x6b. */

#include "game/enemy_common.h"

extern void Ov289_CreateNamedEntity(int);

void Ov289_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x6b, (void *)Ov289_CreateNamedEntity);
}
