/* Registers Ov139_CreateNamedEntity as the factory for entity class 0xc. */

#include "game/enemy_common.h"

extern void Ov139_CreateNamedEntity(int);

void Ov139_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x0c, (void *)Ov139_CreateNamedEntity);
}
