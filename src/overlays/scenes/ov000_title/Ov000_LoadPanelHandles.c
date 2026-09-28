/* Fill the scene's 18-entry handle table from resource ids 4, 5, then 6..21 -- the first two
 * written individually and the remaining sixteen in a loop, all through Ov000_FindEntryById against
 * the embedded object. LAYOUT CONFLICT, recorded rather than resolved: this function is handed the
 * current root heap block, which for ov000 is Ov000SceneContext, and it writes 18 ints at +8
 * (covering +8..+0x4f). Ov000SceneContext currently declares renderNode at +12, pad0010 at +16 and
 * selectionObject at +76, all inside that span. One of the two views is wrong and this function
 * cannot tell you which, so nothing was merged. Settle it against whatever allocates or clears the
 * whole object before building on either. */

#include "nitro/types.h"

typedef struct {
    u8 pad_0000[8];
    int handles[18];
    u8 pad_0050[0x4b88];
    u8 object[1];
} OverlayContext;

extern OverlayContext *NNSi_FndGetCurrentRootHeap(void);
extern int Ov000_FindEntryById(void *object, int id);

void Ov000_LoadPanelHandles(void) {
    OverlayContext *context = NNSi_FndGetCurrentRootHeap();
    int *handles = context->handles;
    int i;

    context->handles[0] = Ov000_FindEntryById(context->object, 4);
    handles[1] = Ov000_FindEntryById(context->object, 5);
    for (i = 0; i < 16; i++) {
        handles[i + 2] = Ov000_FindEntryById(context->object, i + 6);
    }
}
