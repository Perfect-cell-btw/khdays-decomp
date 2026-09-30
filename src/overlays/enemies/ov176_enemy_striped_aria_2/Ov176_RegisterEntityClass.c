/* Registers Ov176_CreateNamedEntity as the factory for enemy class 0x1e (Striped Aria) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov176_CreateNamedEntity(int);

void Ov176_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_STRIPED_ARIA, Ov176_CreateNamedEntity);
}
