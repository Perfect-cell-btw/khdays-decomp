/* Registers Ov140_CreateNamedEntity as the factory for enemy class 0x0c (Icy Cube) with the shared
 * enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov140_CreateNamedEntity(int);

void Ov140_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_ICY_CUBE, Ov140_CreateNamedEntity);
}
