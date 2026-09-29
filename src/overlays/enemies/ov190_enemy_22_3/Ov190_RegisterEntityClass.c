/* Registers Ov190_CreateNamedEntity as the factory for entity class 0x22. */

#include "game/enemy_common.h"

extern void Ov190_CreateNamedEntity(int);

void Ov190_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x22, (void *)Ov190_CreateNamedEntity);
}
