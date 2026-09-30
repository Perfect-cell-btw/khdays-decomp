/* Registers Ov237_CreateNamedEntity as the factory for enemy class 0x40 (Crimson Prankster) with
 * the shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov237_CreateNamedEntity(int);
int Ov237_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_CRIMSON_PRANKSTER, (void *)&Ov237_CreateNamedEntity);
}
