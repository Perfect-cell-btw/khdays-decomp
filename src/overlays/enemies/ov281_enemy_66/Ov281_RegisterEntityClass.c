/* Registers Ov281_CreateNamedEntity as the factory for entity class 0x66. */

#include "game/enemy_common.h"

extern void Ov281_CreateNamedEntity(int);

void Ov281_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x66, (void *)Ov281_CreateNamedEntity);
}
