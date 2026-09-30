/* Registers Ov156_CreateNamedEntity as the factory for enemy class 0x15 (Blizzard Plant) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov156_CreateNamedEntity(int);

void Ov156_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_BLIZZARD_PLANT, Ov156_CreateNamedEntity);
}
