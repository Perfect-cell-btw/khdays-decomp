/* Registers Ov208_CreateNamedEntity as the factory for enemy class 0x2a (Clay Armor) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov208_CreateNamedEntity(int);
int Ov208_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_CLAY_ARMOR, (void *)&Ov208_CreateNamedEntity);
}
