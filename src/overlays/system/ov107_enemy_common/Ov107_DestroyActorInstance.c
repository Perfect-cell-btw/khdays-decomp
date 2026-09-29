#include "game/enemy_common.h"

extern void FreeInstanceMemory(int block);
extern void Ov107_Spawner_FreeDataBlocks(int obj);
/* Destructor: release the optional sub-block at +0xf4, run the two subclass teardowns, then the
 * base destructor. */
void Ov107_DestroyActorInstance(int obj) {
    if (*(int *)(obj + 0xf4) != 0) {
        FreeInstanceMemory(*(int *)(obj + 0xf4));
    }
    Ov107_Spawner_FreeDataBlocks(obj);
    Ov107_StartObject((void *)obj);
    Ov107_DestroyInstance(obj);
}
