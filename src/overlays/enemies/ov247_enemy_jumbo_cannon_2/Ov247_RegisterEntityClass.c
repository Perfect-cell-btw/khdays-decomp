/* Registers Ov247_CreateNamedEntity as the factory for enemy class 0x48 (Jumbo Cannon) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov247_CreateNamedEntity(int);
int Ov247_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_JUMBO_CANNON, (void *)&Ov247_CreateNamedEntity);
}
