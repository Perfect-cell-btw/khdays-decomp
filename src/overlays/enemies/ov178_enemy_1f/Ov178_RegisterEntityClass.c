/* Registers Ov178_CreateNamedEntity as the factory for entity class 0x1f. */

#include "game/enemy_common.h"

extern void Ov178_CreateNamedEntity(int);

void Ov178_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1f, (void *)Ov178_CreateNamedEntity);
}
