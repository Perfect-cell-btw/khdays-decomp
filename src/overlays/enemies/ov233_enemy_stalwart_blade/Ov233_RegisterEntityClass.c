/* Registers Ov233_CreateNamedEntity as the factory for enemy class 0x3c (Stalwart Blade) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov233_CreateNamedEntity(int);
int Ov233_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_STALWART_BLADE, (void *)&Ov233_CreateNamedEntity);
}
