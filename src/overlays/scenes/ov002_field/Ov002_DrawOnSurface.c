/* Draw onto a tiled surface, bracketed by the surface's begin/end pair
 * (Obj_InvokeInnerVtable4 / EnqueueObjGfxCommand). Takes FIVE arguments: the fifth arrives on
 * the stack and is forwarded as the sixth word of the draw call, with a literal
 * 4 wedged in as the fifth.
 */

#include "game/engine.h"

extern void EnqueueObjGfxCommand(void *surface);

void Ov002_DrawOnSurface(void *surface, int a, int b, int c, int e) {
    Obj_InvokeInnerVtable4(surface);
    Obj_ForwardToSub1c(surface, a, b, c, 4, e);
    EnqueueObjGfxCommand(surface);
}
