/* Interworking tail-call veneer (`ldr ip,[pc] ; bx ip`): forwards to TileTextRenderer_Destroy. */

#include "game/engine.h"

void *func_ov024_020835cc(int *r0) {
    return TileTextRenderer_Destroy(r0);
}
