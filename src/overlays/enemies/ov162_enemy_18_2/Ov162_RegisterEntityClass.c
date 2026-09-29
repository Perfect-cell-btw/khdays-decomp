/* Registers Ov162_CreateNamedEntity as the factory for entity class 0x18. */

#include "game/enemy_common.h"

extern void Ov162_CreateNamedEntity(int);

void Ov162_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x18, (void *)Ov162_CreateNamedEntity);
}
