/* Registers Ov254_CreateNamedEntity as the factory for enemy class 0x4e (Antlion) with the shared
 * enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov254_CreateNamedEntity(int);
int Ov254_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_ANTLION, (void *)&Ov254_CreateNamedEntity);
}
