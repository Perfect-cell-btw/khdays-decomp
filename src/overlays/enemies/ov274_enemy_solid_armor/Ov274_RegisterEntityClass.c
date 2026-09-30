/* Registers Ov274_CreateNamedEntity as the factory for enemy class 0x60 (Solid Armor) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov274_CreateNamedEntity(int);
int Ov274_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_SOLID_ARMOR, (void *)&Ov274_CreateNamedEntity);
}
