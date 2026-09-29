/* Enqueues the object's surface upload (command 0xb, or 0xa in the alternate mode). Returns what
 * GFXi_EnqueueCommand returns. */

#include "game/engine.h"

extern int GFXi_EnqueueCommand(int a, int b, int c, int d);

int Gfx_EnqueueSurface(int param_1) {
    int mode = (LoadGlobalU16At0() & 2) == 0 ? 0xb : 10;
    return GFXi_EnqueueCommand(mode, 0, *(int *)(param_1 + 0x94) + 0xc,
                  *(int *)(*(int *)(param_1 + 0x94) + 8));
}
