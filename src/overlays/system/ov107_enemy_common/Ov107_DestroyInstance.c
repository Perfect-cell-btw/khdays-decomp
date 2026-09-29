#include "game/enemy_common.h"

extern void ClearListAndDestroy(int *list);
extern void FreeInstanceMemory(int obj);
/* Destructor: destroy the child list (obj+0x3c) if present, run the subclass teardown, then free
 * the instance. */
void Ov107_DestroyInstance(int obj) {
    if (*(int **)(obj + 0x3c) != 0) {
        ClearListAndDestroy(*(int **)(obj + 0x3c));
        *(int *)(obj + 0x3c) = 0;
    }
    Ov107_Scene_RemoveObject(obj);
    FreeInstanceMemory(obj);
}
