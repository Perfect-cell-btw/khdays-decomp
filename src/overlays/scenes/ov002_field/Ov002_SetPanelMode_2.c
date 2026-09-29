/* NOTE: data_ov002_0207f618 is NOT the Ov002PanelContext object -- that layout
 * belongs to data_ov002_0207f614, whose accessor family produced its named
 * fields (+0x3c, +0x48, +0x18c, +0x1b8). f618's own accessors stride by 0x18 at
 * +0x7c and by 4 at +0xce, which do not fit. Two neighbouring globals, two
 * objects; this one is left as its own type until enough of it is known.
 *
 * Set the panel mode at +0x2c, ignoring the call when there is no context or the
 * mode is already the one asked for. Arming the tag-tracker node for tag 0x1a is
 * done BEFORE the field is written, then the panel is relaid out. Switching to
 * mode 0 raises scene event 0x4f; switching to any other mode plays the cancel
 * sound, but only when Ov002_RunShutdownHook reports the panel unlocked. */

#include "game/engine.h"

typedef struct {
    char pad00[0x2c];
    int nPanelMode;         /* +0x2c */
} Ov002ModeContext;

extern int Ov002_Ctx_FindActiveEntryByTag(int tag);
extern void Ov002_Ctx_SetTagTrackerNodeArmed_5(int node, int armed);
extern void Ov002_RepaintPanelRows(void);
extern int Ov002_ForwardToSubDc(int event);
extern void Ov002_Ctx_InvokeTagTrackerCallback(int);
extern int Ov002_RunShutdownHook(void);

extern Ov002ModeContext *data_ov002_0207f618;

void Ov002_SetPanelMode_2(int mode) {
    Ov002ModeContext *ctx = data_ov002_0207f618;

    if (ctx == 0 || ctx->nPanelMode == mode) {
        return;
    }

    Ov002_Ctx_SetTagTrackerNodeArmed_5(Ov002_Ctx_FindActiveEntryByTag(0x1a), mode);
    ctx->nPanelMode = mode;
    Ov002_RepaintPanelRows();

    /* The non-zero arm is written first so it stays inline and the mode-0 arm is
     * emitted out of line at the tail, matching the ROM's forward beq. */
    if (mode != 0) {
        if (Ov002_RunShutdownHook() == 0) {
            PlaySoundChecked(0, 0x10);
        }
    } else {
        Ov002_Ctx_InvokeTagTrackerCallback(Ov002_ForwardToSubDc(0x4f));
    }
}
