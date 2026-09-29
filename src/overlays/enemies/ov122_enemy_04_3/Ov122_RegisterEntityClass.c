/* Registers Ov122_CreateNamedEntity as the factory for entity class 0x4. */

#include "game/enemy_common.h"

extern void Ov122_CreateNamedEntity(int);

void Ov122_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x04, (void *)Ov122_CreateNamedEntity);
}
