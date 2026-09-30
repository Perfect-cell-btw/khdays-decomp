/* Registers Ov248_CreateNamedEntity as the factory for enemy class 0x49 (Chill Ripper) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern int Ov107_RegisterHandler(int, void *);
extern int Ov248_CreateNamedEntity(int);
int Ov248_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(ENEMY_CHILL_RIPPER, (void *)&Ov248_CreateNamedEntity);
}
