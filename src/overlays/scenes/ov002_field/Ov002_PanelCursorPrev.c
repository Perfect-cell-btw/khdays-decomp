/* Moves the command deck's cursor one step back (Ov002_PanelStepCursor) once the panel's
 * transition has finished and it has a target (+0x1a8), with the cursor sound when it moved.
 * Up with X held calls it (Ov022_UpdateCommandInput); Ov002_PanelCursorNext is the other way. */

#include "game/engine.h"

typedef struct {
    char pad00[0x1a8];
    int pTarget;            /* +0x1a8 */
} Ov002PanelContext;

extern int Ov002_GetPanelField018c(void);
extern int Ov002_PanelStepCursor(void);

extern Ov002PanelContext *data_ov002_0207f614;

void Ov002_PanelCursorPrev(void) {
    Ov002PanelContext *ctx = data_ov002_0207f614;

    if (Ov002_GetPanelField018c() != 0 && ctx->pTarget != 0) {
        if (Ov002_PanelStepCursor() != 0) {
            PlaySound(0, 0);
        }
    }
}
