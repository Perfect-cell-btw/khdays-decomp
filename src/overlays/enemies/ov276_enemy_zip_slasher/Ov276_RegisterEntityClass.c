/* Registers Ov276_AllocActorWithName as the factory for enemy class 0x61 (Zip Slasher) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov276_AllocActorWithName(int);

void Ov276_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_ZIP_SLASHER, Ov276_AllocActorWithName);
}
