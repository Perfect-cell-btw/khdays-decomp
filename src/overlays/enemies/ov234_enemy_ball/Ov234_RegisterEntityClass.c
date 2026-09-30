/* Registers Ov234_CreateNamedEntity as the factory for enemy class 0x3d (Ball) with the shared
 * enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov234_CreateNamedEntity(int);

void Ov234_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_BALL, Ov234_CreateNamedEntity);
}
