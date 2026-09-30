/* Registers Ov224_CreateNamedEntity as the factory for enemy class 0x35 (Avalanche) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov224_CreateNamedEntity(int);
int Ov224_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_AVALANCHE, (void *)&Ov224_CreateNamedEntity);
}
