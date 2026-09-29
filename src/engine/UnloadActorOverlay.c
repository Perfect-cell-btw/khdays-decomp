/* Unloads overlay 107 (the actor framework). */

#include "nitro/types.h"
#include "game/engine.h"

typedef u32 FSOverlayID;

extern u32 OVERLAY_107_ID[1];
#define FS_OVERLAY_ID_ov107 ((FSOverlayID)(u32) & (OVERLAY_107_ID))

void UnloadActorOverlay(void) {
    UnloadOverlaySync(0, FS_OVERLAY_ID_ov107);
}
