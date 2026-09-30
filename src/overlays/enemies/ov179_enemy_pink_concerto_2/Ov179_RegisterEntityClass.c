/* Registers Ov179_CreateNamedEntity as the factory for enemy class 0x1f (Pink Concerto) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov179_CreateNamedEntity(int);

void Ov179_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_PINK_CONCERTO, Ov179_CreateNamedEntity);
}
