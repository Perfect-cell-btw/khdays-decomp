/* Registers Ov174_CreateNamedEntity as the factory for entity class 0x1d. */

#include "game/enemy_common.h"

extern void Ov174_CreateNamedEntity(int);

void Ov174_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1d, (void *)Ov174_CreateNamedEntity);
}
