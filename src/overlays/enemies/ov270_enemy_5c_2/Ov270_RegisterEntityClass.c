/* Registers Ov270_CreateNamedEntity as the factory for entity class 0x5c. */

#include "game/enemy_common.h"

extern void Ov270_CreateNamedEntity(int);

void Ov270_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x5c, (void *)Ov270_CreateNamedEntity);
}
