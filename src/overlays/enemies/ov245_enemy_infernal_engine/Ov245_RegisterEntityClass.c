/* Registers Ov245_CreateNamedEntity as the factory for enemy class 0x47 (Infernal Engine) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov245_CreateNamedEntity(int);
int Ov245_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_INFERNAL_ENGINE, (void *)&Ov245_CreateNamedEntity);
}
