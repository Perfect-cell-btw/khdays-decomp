/* Registers Ov284_CreateNamedEntity as the factory for enemy class 0x69 (Tentaclaw) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov284_CreateNamedEntity(int);

void Ov284_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_TENTACLAW, Ov284_CreateNamedEntity);
}
