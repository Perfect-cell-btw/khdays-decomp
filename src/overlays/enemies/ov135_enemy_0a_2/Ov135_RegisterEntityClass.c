/* Registers Ov135_CreateNamedEntity as the factory for entity class 0xa. */

#include "game/enemy_common.h"

extern void Ov135_CreateNamedEntity(int);

void Ov135_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x0a, (void *)Ov135_CreateNamedEntity);
}
