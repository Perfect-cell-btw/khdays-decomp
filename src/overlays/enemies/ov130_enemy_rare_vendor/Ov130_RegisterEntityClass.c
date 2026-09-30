/* Registers Ov130_CreateNamedEntity as the factory for enemy class 0x08 (Rare Vendor) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov130_CreateNamedEntity(int);

void Ov130_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_RARE_VENDOR, Ov130_CreateNamedEntity);
}
