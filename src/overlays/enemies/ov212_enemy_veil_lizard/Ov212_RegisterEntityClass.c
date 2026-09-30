/* Registers Ov212_CreateNamedEntity as the factory for enemy class 0x2c (Veil Lizard) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov212_CreateNamedEntity(int);
int Ov212_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_VEIL_LIZARD, (void *)&Ov212_CreateNamedEntity);
}
