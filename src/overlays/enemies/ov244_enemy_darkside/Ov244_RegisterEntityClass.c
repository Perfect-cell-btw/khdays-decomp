/* Registers Ov244_CreateNamedEntity_2 as the factory for enemy class 0x46 (Darkside) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov244_CreateNamedEntity_2(int);
int Ov244_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_DARKSIDE, (void *)&Ov244_CreateNamedEntity_2);
}
