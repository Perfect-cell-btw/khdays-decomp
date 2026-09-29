/* Registers Ov123_CreateNamedEntity as the factory for entity class 0x5. */

#include "game/enemy_common.h"

extern void Ov123_CreateNamedEntity(int);

void Ov123_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x05, (void *)Ov123_CreateNamedEntity);
}
