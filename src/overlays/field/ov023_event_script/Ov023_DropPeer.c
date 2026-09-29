#include "game/engine.h"

extern void Ov023_ReleaseScreenActors(void);
extern void Ov023_HideScreenActors(void);
extern void Ov023_ReleaseScreenSprites(void);
extern char *data_ov023_0208a784;

/* Drops a peer that has gone away: unless it is still in state 2 or 3, clears its bit, rebuilds
 * the roster and republishes the lobby. */
void Ov023_DropPeer(int peer) {
    int state;
    if (EntityMgr_GetModelGroupCount() <= peer) {
        return;
    }
    state = *(int *)((&data_ov023_0208a784)[1] + 0x875e4);
    if (state != 3 && state != 2) {
        Render_ApplyFactorToViews(1 << peer, 1 << 0xc);
    }
    Ov023_ReleaseScreenActors();
    Render_DrawViewLists((unsigned short)peer);
    Ov023_HideScreenActors();
    Ov023_ReleaseScreenSprites();
}
