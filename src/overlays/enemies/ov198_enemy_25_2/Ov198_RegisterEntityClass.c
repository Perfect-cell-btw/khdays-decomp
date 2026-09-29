/* Registers Ov198_CreateNamedEntity as the factory for entity class 0x25. */

#include "game/enemy_common.h"

extern void Ov198_CreateNamedEntity(int);

void Ov198_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x25, (void *)Ov198_CreateNamedEntity);
}
