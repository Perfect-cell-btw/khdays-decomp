/* Registers Ov196_CreateNamedEntity as the factory for entity class 0x24. */

#include "game/enemy_common.h"

extern void Ov196_CreateNamedEntity(int);

void Ov196_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x24, (void *)Ov196_CreateNamedEntity);
}
