/* Registers Ov299_CreateNamedEntity as the factory for entity class 0x73. */

#include "game/enemy_common.h"

extern void Ov299_CreateNamedEntity(int);

void Ov299_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x73, (void *)Ov299_CreateNamedEntity);
}
