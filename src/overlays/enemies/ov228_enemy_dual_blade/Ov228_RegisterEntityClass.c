/* Registers Ov228_CreateNamedEntity as the factory for enemy class 0x39 (Dual Blade) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov228_CreateNamedEntity(int);
int Ov228_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_DUAL_BLADE, (void *)&Ov228_CreateNamedEntity);
}
