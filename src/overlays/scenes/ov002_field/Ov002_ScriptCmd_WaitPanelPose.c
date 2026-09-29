/* Advance the ov002 request one step. If Ov002_ResolveSelectedPanel reports the queue
 * already resolved, finish immediately and post event 0x20ef. Otherwise pick the
 * pose from the sub-object's flag byte at +0x4a4, drain any pending entry, and
 * only when Ov002_GetPanelField018c says the step is complete either hand off to
 * Ov002_DrawRecordLine (flag set) or finish and post the same event. */

#include "game/engine.h"

extern int Ov002_ResolveSelectedPanel(void);
extern void Ov002_ReleaseBattleViewFocus(void);
extern void Ov002_SetPanelField003c(int pose);
extern void Ov002_SetSeatFlag(int a, int b);
extern int Ov002_World_IsFlagBitSet(int a);
extern int Ov002_GetPanelField018c(void);
extern void Ov002_DrawRecordLine(void *self, void *req);

int Ov002_ScriptCmd_WaitPanelPose(int *self, char *req) {
    int pose = ScriptVm_ReadOperandInt(self, req + 8);

    if (Ov002_ResolveSelectedPanel() != 0) {
        Ov002_ReleaseBattleViewFocus();
        GameState_SetField(0x20ef, 1, 0);
        return 1;
    }

    if (*(signed char *)(self[0x4a] + 0x4a4) != 0) {
        Ov002_SetPanelField003c(1);
    } else {
        Ov002_SetPanelField003c(pose);
        Ov002_SetSeatFlag(0, 0);
    }

    if (Ov002_World_IsFlagBitSet(0) != 0) {
        Ov002_SetPanelField003c(1);
        Ov002_SetSeatFlag(0, 0);
    }

    if (Ov002_GetPanelField018c() != 0) {
        if (*(signed char *)(self[0x4a] + 0x4a4) != 0) {
            Ov002_DrawRecordLine(self, req);
            return 0;
        }
        Ov002_ReleaseBattleViewFocus();
        GameState_SetField(0x20ef, 1, 0);
        return 1;
    }

    return 0;
}
