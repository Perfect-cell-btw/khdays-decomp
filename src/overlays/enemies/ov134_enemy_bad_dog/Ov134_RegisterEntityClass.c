/* Registers Ov134_CreateNamedEntity as the factory for enemy class 0x0a (Bad Dog) with the shared
 * enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov134_CreateNamedEntity(int);

void Ov134_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_BAD_DOG, Ov134_CreateNamedEntity);
}
