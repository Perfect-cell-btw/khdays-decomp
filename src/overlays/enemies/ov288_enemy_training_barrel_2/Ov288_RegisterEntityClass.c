/* Registers Ov288_CreateNamedEntity as the factory for enemy class 0x6b (Training Barrel) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov288_CreateNamedEntity(int);

void Ov288_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_TRAINING_BARREL, Ov288_CreateNamedEntity);
}
