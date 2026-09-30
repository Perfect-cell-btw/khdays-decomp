/* Registers Ov207_CreateNamedEntity as the factory for enemy class 0x29 (Large Armor) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov207_CreateNamedEntity(int);
int Ov207_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_LARGE_ARMOR, (void *)&Ov207_CreateNamedEntity);
}
