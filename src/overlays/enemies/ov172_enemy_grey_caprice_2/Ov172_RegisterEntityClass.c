/* Registers Ov172_CreateNamedEntity as the factory for enemy class 0x1c (Grey Caprice) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov172_CreateNamedEntity(int);

void Ov172_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_GREY_CAPRICE, Ov172_CreateNamedEntity);
}
