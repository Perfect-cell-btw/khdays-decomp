/* Flushes the object's OAM buffer and resets its slot count. */

#include "game/engine.h"

void Obj_CommitAllSlots(char *arg0) {
    OamBuffer_Flush(arg0, 0);
    *(int *)(arg0 + 0x4634) = 0;
}
