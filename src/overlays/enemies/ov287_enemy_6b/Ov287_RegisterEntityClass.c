/* Registers Ov287_CreateNamedEntity as the factory for entity class 0x6b. */

#include "game/enemy_common.h"

extern void Ov287_CreateNamedEntity(int);

void Ov287_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x6b, (void *)Ov287_CreateNamedEntity);
}
