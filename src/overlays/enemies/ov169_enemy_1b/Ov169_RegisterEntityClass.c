/* Registers Ov169_CreateNamedEntity as the factory for entity class 0x1b. */

#include "game/enemy_common.h"

extern void Ov169_CreateNamedEntity(int);

void Ov169_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1b, (void *)Ov169_CreateNamedEntity);
}
