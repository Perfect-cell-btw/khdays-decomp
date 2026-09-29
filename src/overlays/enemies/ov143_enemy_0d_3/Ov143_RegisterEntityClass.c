/* Registers Ov143_CreateNamedEntity as the factory for entity class 0xd. */

#include "game/enemy_common.h"

extern void Ov143_CreateNamedEntity(int);

void Ov143_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x0d, (void *)Ov143_CreateNamedEntity);
}
