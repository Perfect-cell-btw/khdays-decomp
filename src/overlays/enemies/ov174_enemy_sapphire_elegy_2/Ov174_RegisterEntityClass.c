/* Registers Ov174_CreateNamedEntity as the factory for enemy class 0x1d (Sapphire Elegy) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov174_CreateNamedEntity(int);

void Ov174_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_SAPPHIRE_ELEGY, Ov174_CreateNamedEntity);
}
