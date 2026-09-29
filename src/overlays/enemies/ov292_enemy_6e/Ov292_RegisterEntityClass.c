/* Registers Ov292_CreateNamedEntity as the factory for entity class 0x6e. */

#include "game/enemy_common.h"

extern void Ov292_CreateNamedEntity(int);

void Ov292_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x6e, (void *)Ov292_CreateNamedEntity);
}
