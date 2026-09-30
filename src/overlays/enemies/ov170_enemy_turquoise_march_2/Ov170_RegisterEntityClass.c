/* Registers Ov170_CreateNamedEntity as the factory for enemy class 0x1b (Turquoise March) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov170_CreateNamedEntity(int);

void Ov170_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_TURQUOISE_MARCH, Ov170_CreateNamedEntity);
}
