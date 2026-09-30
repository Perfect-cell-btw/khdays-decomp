/* Registers Ov279_CreateNamedEntity as the factory for enemy class 0x64 (Carrier Ghost) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov279_CreateNamedEntity(int);
int Ov279_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_CARRIER_GHOST, (void *)&Ov279_CreateNamedEntity);
}
