/* Registers Ov175_CreateNamedEntity as the factory for entity class 0x1e. */

#include "game/enemy_common.h"

extern void Ov175_CreateNamedEntity(int);

void Ov175_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1e, (void *)Ov175_CreateNamedEntity);
}
