/* Registers Ov287_CreateNamedEntity as the factory for enemy class 0x6b (Training Barrel) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov287_CreateNamedEntity(int);

void Ov287_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_TRAINING_BARREL, Ov287_CreateNamedEntity);
}
