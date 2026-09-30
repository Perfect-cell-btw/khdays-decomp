/* Registers Ov267_CreateNamedEntity as the factory for enemy class 0x5a (Lurk Lizard) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov267_CreateNamedEntity(int);
int Ov267_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_LURK_LIZARD, (void *)&Ov267_CreateNamedEntity);
}
