/* Registers Ov263_CreateNamedEntity as the factory for enemy class 0x57 (Sky Grappler) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov263_CreateNamedEntity(int);
int Ov263_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_SKY_GRAPPLER, (void *)&Ov263_CreateNamedEntity);
}
