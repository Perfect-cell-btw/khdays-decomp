/* Registers Ov242_CreateNamedEntity as the factory for entity class 0x44. */

#include "game/enemy_common.h"

extern void Ov242_CreateNamedEntity(int);

void Ov242_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x44, (void *)Ov242_CreateNamedEntity);
}
