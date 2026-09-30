/* Registers Ov252_CreateNamedEntity as the factory for enemy class 0x4c (Ruler of the Sky) with
 * the shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov252_CreateNamedEntity(int);
int Ov252_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_RULER_OF_THE_SKY, (void *)&Ov252_CreateNamedEntity);
}
