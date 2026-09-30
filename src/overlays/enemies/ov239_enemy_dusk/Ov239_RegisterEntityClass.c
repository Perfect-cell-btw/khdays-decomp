/* Registers Ov239_CreateNamedEntity as the factory for enemy class 0x42 (Dusk) with the shared
 * enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov239_CreateNamedEntity(int);

void Ov239_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_DUSK, Ov239_CreateNamedEntity);
}
