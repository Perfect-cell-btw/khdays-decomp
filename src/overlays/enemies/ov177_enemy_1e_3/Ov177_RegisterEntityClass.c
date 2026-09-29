/* Registers Ov177_CreateNamedEntity as the factory for entity class 0x1e. */

#include "game/enemy_common.h"

extern void Ov177_CreateNamedEntity(int);

void Ov177_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1e, (void *)Ov177_CreateNamedEntity);
}
