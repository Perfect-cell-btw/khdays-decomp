/* Registers Ov205_CreateNamedEntity as the factory for enemy class 0x28 (Snowy Crystal) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov205_CreateNamedEntity(int);

void Ov205_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_SNOWY_CRYSTAL, Ov205_CreateNamedEntity);
}
