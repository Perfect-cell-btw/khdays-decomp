/* Registers Ov249_CreateNamedEntity as the factory for enemy class 0x4a (Heat Saber) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov249_CreateNamedEntity(int);
int Ov249_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_HEAT_SABER, (void *)&Ov249_CreateNamedEntity);
}
