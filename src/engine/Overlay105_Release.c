/* Overlay105_Release -- release overlay 105 if this module is the one holding it.
 *
 * The mirror image of Overlay105_Load: the same data_027e0060 latch, cleared instead of
 * set, and the same linker-absolute FS_OVERLAY_ID pool word. See that file for why the
 * id cannot be spelled as the integer 105. */

#include "nitro/types.h"

typedef u32 FSOverlayID;

extern u32 OVERLAY_105_ID[1];
#define FS_OVERLAY_ID_ov105 ((FSOverlayID)(u32) & (OVERLAY_105_ID))

extern s8 data_027e0060;

extern void UnloadOverlaySync(int target, FSOverlayID id);

void Overlay105_Release(void)
{
    if (data_027e0060 == 0) {
        return;
    }
    UnloadOverlaySync(0, FS_OVERLAY_ID_ov105);
    data_027e0060 = 0;
}
