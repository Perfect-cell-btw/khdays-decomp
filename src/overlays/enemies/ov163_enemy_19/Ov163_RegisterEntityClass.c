/* Registers Ov163_CreateNamedEntity as the factory for entity class 0x19. */

#include "game/enemy_common.h"

extern void Ov163_CreateNamedEntity(int);

void Ov163_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x19, (void *)Ov163_CreateNamedEntity);
}
