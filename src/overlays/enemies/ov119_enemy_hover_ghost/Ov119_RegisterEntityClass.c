/* Registers Ov119_CreateNamedEntity as the factory for enemy class 0x03 (Hover Ghost) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov119_CreateNamedEntity(int);
int Ov119_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_HOVER_GHOST, (void *)&Ov119_CreateNamedEntity);
}
