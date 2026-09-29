/* Registers Ov150_CreateNamedEntity as the factory for entity class 0x12. */

#include "game/enemy_common.h"

extern void Ov150_CreateNamedEntity(int);

void Ov150_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x12, (void *)Ov150_CreateNamedEntity);
}
