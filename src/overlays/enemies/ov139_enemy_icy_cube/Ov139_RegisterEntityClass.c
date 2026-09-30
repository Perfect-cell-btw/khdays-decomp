/* Registers Ov139_CreateNamedEntity as the factory for enemy class 0x0c (Icy Cube) with the shared
 * enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov139_CreateNamedEntity(int);

void Ov139_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_ICY_CUBE, Ov139_CreateNamedEntity);
}
