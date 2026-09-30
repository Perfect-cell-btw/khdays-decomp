/* Registers Ov209_CreateNamedEntity as the factory for enemy class 0x2a (Clay Armor) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov209_CreateNamedEntity(int);
int Ov209_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_CLAY_ARMOR, (void *)&Ov209_CreateNamedEntity);
}
