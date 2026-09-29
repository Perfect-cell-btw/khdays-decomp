/* Registers Ov164_CreateNamedEntity as the factory for entity class 0x19. */

#include "game/enemy_common.h"

extern void Ov164_CreateNamedEntity(int);

void Ov164_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x19, (void *)Ov164_CreateNamedEntity);
}
