/* Registers Ov158_CreateNamedEntity as the factory for enemy class 0x16 (Ice Cannon) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov158_CreateNamedEntity(int);
int Ov158_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_ICE_CANNON, (void *)&Ov158_CreateNamedEntity);
}
