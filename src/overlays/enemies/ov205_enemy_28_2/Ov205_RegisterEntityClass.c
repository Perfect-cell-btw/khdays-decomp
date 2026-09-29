/* Registers Ov205_CreateNamedEntity as the factory for entity class 0x28. */

#include "game/enemy_common.h"

extern void Ov205_CreateNamedEntity(int);

void Ov205_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x28, (void *)Ov205_CreateNamedEntity);
}
