/* Registers Ov220_CreateNamedEntity as the factory for entity class 0x32. */

#include "game/enemy_common.h"

extern void Ov220_CreateNamedEntity(int);

void Ov220_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x32, (void *)Ov220_CreateNamedEntity);
}
