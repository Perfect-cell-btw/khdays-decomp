/* Registers Ov123_CreateNamedEntity as the factory for enemy class 0x05 (Dire Plant) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov123_CreateNamedEntity(int);

void Ov123_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_DIRE_PLANT, Ov123_CreateNamedEntity);
}
