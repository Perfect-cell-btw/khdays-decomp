/* Registers Ov293_CreateNamedEntity as the factory for entity class 0x6f. */

#include "game/enemy_common.h"

extern void Ov293_CreateNamedEntity(int);

void Ov293_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x6f, (void *)Ov293_CreateNamedEntity);
}
