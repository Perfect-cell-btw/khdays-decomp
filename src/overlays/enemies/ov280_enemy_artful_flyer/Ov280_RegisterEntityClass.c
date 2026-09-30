/* Registers Ov280_CreateNamedEntity as the factory for enemy class 0x65 (Artful Flyer) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov280_CreateNamedEntity(int);
int Ov280_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_ARTFUL_FLYER, (void *)&Ov280_CreateNamedEntity);
}
