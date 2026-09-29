/* Registers Ov147_CreateNamedEntity as the factory for entity class 0x11. */

#include "game/enemy_common.h"

extern void Ov147_CreateNamedEntity(int);

void Ov147_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x11, (void *)Ov147_CreateNamedEntity);
}
