/* Registers Ov121_CreateNamedEntity as the factory for entity class 0x4. */

#include "game/enemy_common.h"

extern void Ov121_CreateNamedEntity(int);

void Ov121_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x04, (void *)Ov121_CreateNamedEntity);
}
