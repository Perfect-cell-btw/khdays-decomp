/* Registers Ov227_CreateNamedEntity as the factory for enemy class 0x38 (Dustflier) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov227_CreateNamedEntity(int);
int Ov227_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_DUSTFLIER, (void *)&Ov227_CreateNamedEntity);
}
