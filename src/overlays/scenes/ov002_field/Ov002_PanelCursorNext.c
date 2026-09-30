/* Moves the command deck's cursor one step forward (Ov002_PanelAdvanceCursor) once the panel's
 * transition has finished and it has a target (+0x1a8), with the cursor sound when it moved.
 * Down with X held calls it (Ov022_UpdateCommandInput), and X alone with Config option 6 = 1. */

#include "game/engine.h"

typedef struct {
    char pad00[0x1a8];
    int pTarget;            /* +0x1a8 */
} Ov002PanelContext;

extern int Ov002_GetPanelField018c(void);
extern int Ov002_PanelAdvanceCursor(void);

extern Ov002PanelContext *data_ov002_0207f614;

void Ov002_PanelCursorNext(void) {
    Ov002PanelContext *ctx = data_ov002_0207f614;

    if (Ov002_GetPanelField018c() != 0 && ctx->pTarget != 0) {
        if (Ov002_PanelAdvanceCursor() != 0) {
            PlaySound(0, 0);
        }
    }
}
