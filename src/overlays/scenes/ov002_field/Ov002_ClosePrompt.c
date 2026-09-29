/* Close the confirmation prompt: clear the pending flag at +0x178 that
 * Ov002_OpenConfirmPrompt latched, re-arm the tag-tracker node for tag 0x1a, and
 * click unless the shutdown hook has already taken over. Raises the +0x28 bit
 * either way, even when the prompt was never open.
 */

#include "game/engine.h"

extern int Ov002_Ctx_FindActiveEntryByTag(int tag);
extern void Ov002_Ctx_SetTagTrackerNodeArmed_5(int node, int armed);
extern void Ov002_RepaintPanelRows(void);
extern int Ov002_RunShutdownHook(void);

extern char *data_ov002_0207f618;

void Ov002_ClosePrompt(int bClick) {
    char *ctx = data_ov002_0207f618;

    *(int *)(ctx + 0x178) = 0;
    Ov002_RepaintPanelRows();

    if (*(int *)(ctx + 0x2c) != 0) {
        Ov002_Ctx_SetTagTrackerNodeArmed_5(Ov002_Ctx_FindActiveEntryByTag(0x1a), 1);
        if (Ov002_RunShutdownHook() == 0 && bClick != 0) {
            PlaySoundChecked(0, 0x10);
        }
    }

    *(unsigned char *)(ctx + 0x28) = *(unsigned char *)(ctx + 0x28) | 8;
}
