/* Registers Ov188_CreateNamedEntity as the factory for entity class 0x22. */

#include "game/enemy_common.h"

extern void Ov188_CreateNamedEntity(int);

void Ov188_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x22, (void *)Ov188_CreateNamedEntity);
}
