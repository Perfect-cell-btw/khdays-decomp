/* Registers Ov298_CreateNamedEntity as the factory for enemy class 0x72 (the class shown as "? ? ?
 * ?") with the shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov298_CreateNamedEntity(int);

void Ov298_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_MYSTERY_72, Ov298_CreateNamedEntity);
}
