/* Registers Ov240_CreateNamedEntity as the factory for enemy class 0x43 (Samurai) with the shared
 * enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov240_CreateNamedEntity(int);

void Ov240_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_SAMURAI, Ov240_CreateNamedEntity);
}
