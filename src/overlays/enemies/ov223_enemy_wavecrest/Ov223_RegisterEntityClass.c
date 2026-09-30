/* Registers Ov223_CreateNamedEntity as the factory for enemy class 0x34 (Wavecrest) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov223_CreateNamedEntity(int);
int Ov223_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_WAVECREST, (void *)&Ov223_CreateNamedEntity);
}
