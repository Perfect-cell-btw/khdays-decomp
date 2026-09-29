/* Registers Ov290_CreateNamedEntity as the factory for entity class 0x6c. */

#include "game/enemy_common.h"

extern void Ov290_CreateNamedEntity(int);

void Ov290_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x6c, (void *)Ov290_CreateNamedEntity);
}
