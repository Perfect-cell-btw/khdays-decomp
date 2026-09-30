/* Registers Ov127_CreateNamedEntity as the factory for enemy class 0x07 (Bulky Vendor) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov127_CreateNamedEntity(int);

void Ov127_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_BULKY_VENDOR, Ov127_CreateNamedEntity);
}
