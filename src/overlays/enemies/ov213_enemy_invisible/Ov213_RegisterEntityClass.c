/* Registers Ov213_CreateNamedEntity as the factory for enemy class 0x2d (Invisible) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov213_CreateNamedEntity(int);
int Ov213_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_INVISIBLE, (void *)&Ov213_CreateNamedEntity);
}
