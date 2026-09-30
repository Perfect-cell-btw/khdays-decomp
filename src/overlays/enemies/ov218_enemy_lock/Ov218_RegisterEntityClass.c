/* Registers Ov218_CreateNamedEntity as the factory for enemy class 0x30 (Lock) with the shared
 * enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov218_CreateNamedEntity(int);
int Ov218_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_LOCK, (void *)&Ov218_CreateNamedEntity);
}
