/* Registers Ov270_CreateNamedEntity as the factory for enemy class 0x5c (Bully Dog) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov270_CreateNamedEntity(int);

void Ov270_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_BULLY_DOG, Ov270_CreateNamedEntity);
}
