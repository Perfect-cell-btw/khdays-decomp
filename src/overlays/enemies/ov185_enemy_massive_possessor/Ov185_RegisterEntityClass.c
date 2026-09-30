/* Registers Ov185_CreateNamedEntity_2 as the factory for enemy class 0x21 (Massive Possessor) with
 * the shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int a, void *handler);
extern void Ov185_CreateNamedEntity_2(void);
int Ov185_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_MASSIVE_POSSESSOR, (void *)&Ov185_CreateNamedEntity_2);
}
