/* Registers Ov131_CreateNamedEntity as the factory for enemy class 0x09 (Minute Bomb) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov131_CreateNamedEntity(int);

void Ov131_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_MINUTE_BOMB, Ov131_CreateNamedEntity);
}
