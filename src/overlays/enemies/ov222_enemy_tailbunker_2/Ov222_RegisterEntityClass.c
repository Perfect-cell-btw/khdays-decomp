/* Registers Ov222_CreateNamedEntity as the factory for enemy class 0x33 (Tailbunker) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov222_CreateNamedEntity(int);
int Ov222_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_TAILBUNKER, (void *)&Ov222_CreateNamedEntity);
}
