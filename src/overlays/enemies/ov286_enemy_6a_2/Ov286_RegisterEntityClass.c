/* Registers Ov286_CreateNamedEntity as the factory for entity class 0x6a. */

#include "game/enemy_common.h"

extern void Ov286_CreateNamedEntity(int);

void Ov286_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x6a, (void *)Ov286_CreateNamedEntity);
}
