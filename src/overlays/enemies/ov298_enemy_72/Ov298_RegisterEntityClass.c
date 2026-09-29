/* Registers Ov298_CreateNamedEntity as the factory for entity class 0x72. */

#include "game/enemy_common.h"

extern void Ov298_CreateNamedEntity(int);

void Ov298_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x72, (void *)Ov298_CreateNamedEntity);
}
