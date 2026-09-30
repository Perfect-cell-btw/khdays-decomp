/* Registers Ov211_CreateNamedEntity as the factory for enemy class 0x2b (Neoshadow) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov211_CreateNamedEntity(int);
int Ov211_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_NEOSHADOW, (void *)&Ov211_CreateNamedEntity);
}
