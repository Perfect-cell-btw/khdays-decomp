/* Registers Ov157_CreateNamedEntity as the factory for entity class 0x15. */

#include "game/enemy_common.h"

extern void Ov157_CreateNamedEntity(int);

void Ov157_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x15, (void *)Ov157_CreateNamedEntity);
}
