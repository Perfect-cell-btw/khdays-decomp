/* Registers Ov198_CreateNamedEntity as the factory for enemy class 0x25 (Tricky Monkey) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov198_CreateNamedEntity(int);

void Ov198_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_TRICKY_MONKEY, Ov198_CreateNamedEntity);
}
