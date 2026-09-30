/* Registers Ov231_CreateNamedEntity as the factory for enemy class 0x3b (Air Battler) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov231_CreateNamedEntity(int);
int Ov231_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_AIR_BATTLER, (void *)&Ov231_CreateNamedEntity);
}
