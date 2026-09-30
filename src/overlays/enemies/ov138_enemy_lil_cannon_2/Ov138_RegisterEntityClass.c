/* Registers Ov138_CreateNamedEntity as the factory for enemy class 0x0b (Li'l Cannon) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov138_CreateNamedEntity(int);
int Ov138_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_LIL_CANNON, (void *)&Ov138_CreateNamedEntity);
}
