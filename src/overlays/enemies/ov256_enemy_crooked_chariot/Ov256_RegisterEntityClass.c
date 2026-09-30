/* Registers Ov256_CreateNamedEntity as the factory for enemy class 0x50 (Crooked Chariot) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov256_CreateNamedEntity(int);
int Ov256_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_CROOKED_CHARIOT, (void *)&Ov256_CreateNamedEntity);
}
