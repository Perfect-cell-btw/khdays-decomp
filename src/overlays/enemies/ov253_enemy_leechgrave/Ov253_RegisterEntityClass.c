/* Registers Ov253_CreateNamedEntity as the factory for enemy class 0x4d (Leechgrave) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov253_CreateNamedEntity(int);
int Ov253_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_LEECHGRAVE, (void *)&Ov253_CreateNamedEntity);
}
