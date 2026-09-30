/* Registers Ov238_CreateNamedEntity as the factory for enemy class 0x41 (Pete) with the shared
 * enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov238_CreateNamedEntity(int);
int Ov238_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_PETE_41, (void *)&Ov238_CreateNamedEntity);
}
