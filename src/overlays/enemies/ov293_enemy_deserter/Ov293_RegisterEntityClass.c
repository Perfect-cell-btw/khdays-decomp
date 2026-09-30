/* Registers Ov293_CreateNamedEntity as the factory for enemy class 0x6f (Deserter) with the shared
 * enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov293_CreateNamedEntity(int);

void Ov293_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_DESERTER, Ov293_CreateNamedEntity);
}
