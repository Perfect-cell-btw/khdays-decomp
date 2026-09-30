/* Registers Ov206_CreateNamedEntity as the factory for enemy class 0x29 (Large Armor) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov206_CreateNamedEntity(int);
int Ov206_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_LARGE_ARMOR, (void *)&Ov206_CreateNamedEntity);
}
