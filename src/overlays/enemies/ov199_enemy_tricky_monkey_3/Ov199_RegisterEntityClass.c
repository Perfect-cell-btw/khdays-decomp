/* Registers Ov199_CreateNamedEntity as the factory for enemy class 0x25 (Tricky Monkey) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov199_CreateNamedEntity(int);
int Ov199_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_TRICKY_MONKEY, (void *)&Ov199_CreateNamedEntity);
}
