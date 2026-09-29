/* Registers Ov136_CreateNamedEntity as the factory for entity class 0xa. */

#include "game/enemy_common.h"

extern void Ov136_CreateNamedEntity(int);

void Ov136_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x0a, (void *)Ov136_CreateNamedEntity);
}
