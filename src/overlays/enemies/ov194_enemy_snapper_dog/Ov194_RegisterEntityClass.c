/* Registers Ov194_CreateNamedEntity as the factory for enemy class 0x24 (Snapper Dog) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov194_CreateNamedEntity(int);

void Ov194_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_SNAPPER_DOG, Ov194_CreateNamedEntity);
}
