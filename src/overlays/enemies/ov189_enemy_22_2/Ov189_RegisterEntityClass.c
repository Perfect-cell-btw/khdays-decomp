/* Registers Ov189_CreateNamedEntity as the factory for entity class 0x22. */

#include "game/enemy_common.h"

extern void Ov189_CreateNamedEntity(int);

void Ov189_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x22, (void *)Ov189_CreateNamedEntity);
}
