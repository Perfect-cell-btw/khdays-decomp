/* Registers Ov141_CreateNamedEntity as the factory for enemy class 0x0d (Loudmouth) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov141_CreateNamedEntity(int);

void Ov141_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_LOUDMOUTH, Ov141_CreateNamedEntity);
}
