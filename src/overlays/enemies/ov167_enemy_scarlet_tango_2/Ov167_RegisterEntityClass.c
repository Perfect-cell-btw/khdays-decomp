/* Registers Ov167_CreateNamedEntity as the factory for enemy class 0x1a (Scarlet Tango) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov167_CreateNamedEntity(int);

void Ov167_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_SCARLET_TANGO, Ov167_CreateNamedEntity);
}
