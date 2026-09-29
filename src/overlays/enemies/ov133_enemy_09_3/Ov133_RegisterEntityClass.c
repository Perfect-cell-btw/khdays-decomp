/* Registers Ov133_CreateNamedEntity as the factory for entity class 0x9. */

#include "game/enemy_common.h"

extern void Ov133_CreateNamedEntity(int);

void Ov133_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x09, (void *)Ov133_CreateNamedEntity);
}
