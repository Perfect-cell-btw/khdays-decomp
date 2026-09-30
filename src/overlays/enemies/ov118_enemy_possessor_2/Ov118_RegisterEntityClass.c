/* Registers Ov118_CreateNamedEntity as the factory for enemy class 0x02 (Possessor) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov118_CreateNamedEntity(int);

void Ov118_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_POSSESSOR, Ov118_CreateNamedEntity);
}
