/* Registers Ov179_CreateNamedEntity as the factory for entity class 0x1f. */

#include "game/enemy_common.h"

extern void Ov179_CreateNamedEntity(int);

void Ov179_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1f, (void *)Ov179_CreateNamedEntity);
}
