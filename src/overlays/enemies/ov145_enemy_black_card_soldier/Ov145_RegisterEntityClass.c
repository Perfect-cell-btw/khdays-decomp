/* Registers Ov145_CreateNamedEntity as the factory for enemy class 0x0f (Black Card Soldier) with
 * the shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov145_CreateNamedEntity(int);

void Ov145_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_BLACK_CARD_SOLDIER, Ov145_CreateNamedEntity);
}
