/* Registers Ov116_CreateNamedEntity as the factory for enemy class 0x01 (Yellow Opera) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov116_CreateNamedEntity(int);

void Ov116_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_YELLOW_OPERA, Ov116_CreateNamedEntity);
}
