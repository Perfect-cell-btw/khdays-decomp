/* Registers Ov271_CreateNamedEntity as the factory for enemy class 0x5d (Destroyer) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov271_CreateNamedEntity(int);
int Ov271_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_DESTROYER, (void *)&Ov271_CreateNamedEntity);
}
