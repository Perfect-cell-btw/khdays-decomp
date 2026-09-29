/* Registers Ov118_CreateNamedEntity as the factory for entity class 0x2. */

#include "game/enemy_common.h"

extern void Ov118_CreateNamedEntity(int);

void Ov118_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x02, (void *)Ov118_CreateNamedEntity);
}
