/* Registers Ov120_CreateNamedEntity as the factory for entity class 0x4. */

#include "game/enemy_common.h"

extern void Ov120_CreateNamedEntity(int);

void Ov120_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x04, (void *)Ov120_CreateNamedEntity);
}
