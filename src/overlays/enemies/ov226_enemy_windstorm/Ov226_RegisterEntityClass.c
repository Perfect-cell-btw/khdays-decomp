/* Registers Ov226_CreateNamedEntity as the factory for enemy class 0x37 (Windstorm) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov226_CreateNamedEntity(int);
int Ov226_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_WINDSTORM, (void *)&Ov226_CreateNamedEntity);
}
