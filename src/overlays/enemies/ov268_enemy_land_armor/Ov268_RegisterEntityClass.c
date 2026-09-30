/* Registers Ov268_CreateNamedEntity as the factory for enemy class 0x5b (Land Armor) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov268_CreateNamedEntity(int);
int Ov268_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_LAND_ARMOR, (void *)&Ov268_CreateNamedEntity);
}
