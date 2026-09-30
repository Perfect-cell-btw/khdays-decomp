/* Registers Ov146_CreateNamedEntity as the factory for enemy class 0x10 (Barrier Master) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov146_CreateNamedEntity(int);
int Ov146_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_BARRIER_MASTER, (void *)&Ov146_CreateNamedEntity);
}
