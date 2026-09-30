/* Registers Ov230_CreateNamedEntity as the factory for enemy class 0x3a (Blitz Spear) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov230_CreateNamedEntity(int);
int Ov230_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_BLITZ_SPEAR, (void *)&Ov230_CreateNamedEntity);
}
