/* Registers Ov156_CreateNamedEntity as the factory for entity class 0x15. */

#include "game/enemy_common.h"

extern void Ov156_CreateNamedEntity(int);

void Ov156_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x15, (void *)Ov156_CreateNamedEntity);
}
