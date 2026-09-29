/* Registers Ov219_CreateNamedEntity as the factory for entity class 0x31. */

#include "game/enemy_common.h"

extern void Ov219_CreateNamedEntity(int);

void Ov219_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x31, (void *)Ov219_CreateNamedEntity);
}
