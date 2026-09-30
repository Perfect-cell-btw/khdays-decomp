/* Registers Ov160_CreateNamedEntity as the factory for enemy class 0x17 (Switch Launcher) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov160_CreateNamedEntity(int);
int Ov160_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_SWITCH_LAUNCHER, (void *)&Ov160_CreateNamedEntity);
}
