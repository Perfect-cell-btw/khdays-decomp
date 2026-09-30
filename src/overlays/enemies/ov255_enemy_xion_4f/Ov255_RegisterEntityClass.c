/* Registers Ov255_CreateNamedEntity as the factory for enemy class 0x4f (Xion) with the shared
 * enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov255_CreateNamedEntity(int);
int Ov255_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_XION_4F, (void *)&Ov255_CreateNamedEntity);
}
