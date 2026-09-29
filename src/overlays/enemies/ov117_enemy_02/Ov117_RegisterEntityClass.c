/* Registers Ov117_CreateNamedEntity as the factory for entity class 0x2. */

#include "game/enemy_common.h"

extern void Ov117_CreateNamedEntity(int);

void Ov117_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x02, (void *)Ov117_CreateNamedEntity);
}
