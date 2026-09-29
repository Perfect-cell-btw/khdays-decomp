/* Registers Ov239_CreateNamedEntity as the factory for entity class 0x42. */

#include "game/enemy_common.h"

extern void Ov239_CreateNamedEntity(int);

void Ov239_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x42, (void *)Ov239_CreateNamedEntity);
}
