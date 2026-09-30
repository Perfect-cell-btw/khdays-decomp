/* Registers Ov210_CreateNamedEntity as the factory for enemy class 0x2b (Neoshadow) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov210_CreateNamedEntity(int);
int Ov210_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_NEOSHADOW, (void *)&Ov210_CreateNamedEntity);
}
