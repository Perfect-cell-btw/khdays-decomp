/* Registers Ov277_CreateNamedEntity_2 as the factory for enemy class 0x62 (Dark Follower) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov277_CreateNamedEntity_2(int);
int Ov277_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_DARK_FOLLOWER, (void *)&Ov277_CreateNamedEntity_2);
}
