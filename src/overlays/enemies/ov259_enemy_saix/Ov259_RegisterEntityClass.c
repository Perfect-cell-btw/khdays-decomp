/* Registers Ov259_CreateNamedEntity as the factory for enemy class 0x53 (Saix) with the shared
 * enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov259_CreateNamedEntity(int);
int Ov259_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_SAIX, (void *)&Ov259_CreateNamedEntity);
}
