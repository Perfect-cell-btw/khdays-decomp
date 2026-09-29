/* Registers Ov144_CreateNamedEntity as the factory for entity class 0xe. */

#include "game/enemy_common.h"

extern void Ov144_CreateNamedEntity(int);

void Ov144_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x0e, (void *)Ov144_CreateNamedEntity);
}
