/* Registers Ov219_CreateNamedEntity as the factory for enemy class 0x31 (Shock) with the shared
 * enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov219_CreateNamedEntity(int);

void Ov219_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_SHOCK, Ov219_CreateNamedEntity);
}
