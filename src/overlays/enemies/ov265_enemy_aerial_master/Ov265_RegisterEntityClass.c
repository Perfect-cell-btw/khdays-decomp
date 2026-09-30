/* Registers Ov265_CreateNamedEntity as the factory for enemy class 0x59 (Aerial Master) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov265_CreateNamedEntity(int);
int Ov265_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_AERIAL_MASTER, (void *)&Ov265_CreateNamedEntity);
}
