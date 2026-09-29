/* Registers Ov300_CreateNamedEntity as the factory for entity class 0x74. */

#include "game/enemy_common.h"

extern void Ov300_CreateNamedEntity(int);

void Ov300_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x74, (void *)Ov300_CreateNamedEntity);
}
