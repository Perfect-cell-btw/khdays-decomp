/* Registers Ov180_CreateNamedEntity as the factory for entity class 0x1f. */

#include "game/enemy_common.h"

extern void Ov180_CreateNamedEntity(int);

void Ov180_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1f, (void *)Ov180_CreateNamedEntity);
}
