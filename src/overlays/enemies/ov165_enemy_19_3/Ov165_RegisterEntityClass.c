/* Registers Ov165_CreateNamedEntity as the factory for entity class 0x19. */

#include "game/enemy_common.h"

extern void Ov165_CreateNamedEntity(int);

void Ov165_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x19, (void *)Ov165_CreateNamedEntity);
}
