/* Play the panel's confirm feedback, but only once the transition has finished
 * AND the panel actually has a target at +0x1a8 -- the two guards share one
 * predicated chain in the ROM. Ov002_PanelAdvanceCursor has the final say. */

#include "game/engine.h"

typedef struct {
    char pad00[0x1a8];
    int pTarget;            /* +0x1a8 */
} Ov002PanelContext;

extern int Ov002_GetPanelField018c(void);
extern int Ov002_PanelAdvanceCursor(void);

extern Ov002PanelContext *data_ov002_0207f614;

void Ov002_PlayPanelConfirm(void) {
    Ov002PanelContext *ctx = data_ov002_0207f614;

    if (Ov002_GetPanelField018c() != 0 && ctx->pTarget != 0) {
        if (Ov002_PanelAdvanceCursor() != 0) {
            PlaySound(0, 0);
        }
    }
}
