/* Registers Ov240_CreateNamedEntity as the factory for entity class 0x43. */

#include "game/enemy_common.h"

extern void Ov240_CreateNamedEntity(int);

void Ov240_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x43, (void *)Ov240_CreateNamedEntity);
}
