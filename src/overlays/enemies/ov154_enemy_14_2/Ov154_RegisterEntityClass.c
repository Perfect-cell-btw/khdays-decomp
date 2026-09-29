/* Registers Ov154_CreateNamedEntity as the factory for entity class 0x14. */

#include "game/enemy_common.h"

extern void Ov154_CreateNamedEntity(int);

void Ov154_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x14, (void *)Ov154_CreateNamedEntity);
}
