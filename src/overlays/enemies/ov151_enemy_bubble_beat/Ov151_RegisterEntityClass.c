/* Registers Ov151_CreateNamedEntity as the factory for enemy class 0x13 (Bubble Beat) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov151_CreateNamedEntity(int);

void Ov151_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_BUBBLE_BEAT, Ov151_CreateNamedEntity);
}
