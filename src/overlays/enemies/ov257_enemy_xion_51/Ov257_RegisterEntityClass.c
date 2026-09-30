/* Registers Ov257_CreateNamedEntity as the factory for enemy class 0x51 (Xion) with the shared
 * enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov257_CreateNamedEntity(int);
int Ov257_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_XION_51, (void *)&Ov257_CreateNamedEntity);
}
