/* Registers Ov264_AllocActorWithName as the factory for enemy class 0x58 (Spiked Crawler) with the
 * shared enemy framework. */
#include "game/enemy_id.h"

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov264_AllocActorWithName(int);

void Ov264_RegisterEntityClass(void) {
    Ov107_RegisterHandler(ENEMY_SPIKED_CRAWLER, Ov264_AllocActorWithName);
}
