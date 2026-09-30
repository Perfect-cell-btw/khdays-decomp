/* Registers Ov200_CreateNamedEntity as the factory for enemy class 0x26 (Guardian) with the shared
 * enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov200_CreateNamedEntity(int);
int Ov200_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_GUARDIAN, (void *)&Ov200_CreateNamedEntity);
}
