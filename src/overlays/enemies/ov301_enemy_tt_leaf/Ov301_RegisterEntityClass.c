/* Registers Ov301_CreateNamedEntity as the factory for enemy class 0x75 (class 0x75) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov301_CreateNamedEntity(int);

void Ov301_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_TT_LEAF, Ov301_CreateNamedEntity);
}
