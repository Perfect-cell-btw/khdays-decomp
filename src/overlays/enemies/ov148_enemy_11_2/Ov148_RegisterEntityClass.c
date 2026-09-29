/* Registers Ov148_CreateNamedEntity as the factory for entity class 0x11. */

#include "game/enemy_common.h"

extern void Ov148_CreateNamedEntity(int);

void Ov148_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x11, (void *)Ov148_CreateNamedEntity);
}
