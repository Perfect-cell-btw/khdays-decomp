/* Registers Ov278_CreateNamedEntity as the factory for enemy class 0x63 (Powered Armor) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov278_CreateNamedEntity(int);
int Ov278_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_POWERED_ARMOR, (void *)&Ov278_CreateNamedEntity);
}
