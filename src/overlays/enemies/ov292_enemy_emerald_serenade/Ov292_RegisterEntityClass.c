/* Registers Ov292_CreateNamedEntity as the factory for enemy class 0x6e (Emerald Serenade) with
 * the shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov292_CreateNamedEntity(int);

void Ov292_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_EMERALD_SERENADE, Ov292_CreateNamedEntity);
}
