/* Registers Ov126_CreateNamedEntity as the factory for enemy class 0x06 (Watcher) with the shared
 * enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov126_CreateNamedEntity(int);
int Ov126_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_WATCHER, (void *)&Ov126_CreateNamedEntity);
}
