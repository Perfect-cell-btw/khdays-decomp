/* Registers Ov131_CreateNamedEntity as the factory for entity class 0x9. */

#include "game/enemy_common.h"

extern void Ov131_CreateNamedEntity(int);

void Ov131_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x09, (void *)Ov131_CreateNamedEntity);
}
