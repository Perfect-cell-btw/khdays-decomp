/* Registers Ov235_CreateNamedEntity as the factory for enemy class 0x3e (Xion) with the shared
 * enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov235_CreateNamedEntity(int);
int Ov235_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_XION_3E, (void *)&Ov235_CreateNamedEntity);
}
