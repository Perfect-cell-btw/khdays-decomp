/* Finish the ov002 request: wipe the sub-object's 0x100-byte block at +0x4a4,
 * hand the request to Ov002_DrawRecordLine, take the battle-view focus and post
 * event 0x20ef with follow-up 1.
 *
 * Refuses (reporting 1) while link phase 1 is running in the boot mode gated by
 * bit 2 of data_0204c240 -- the same gate Ov002_EnterDimmedScene reads. Sibling of
 * Ov002_ScriptCmd_WaitPanelPose, which drives the same request one step at a time; note
 * ScriptVm_ReadOperandInt's result is fetched and discarded here. */

#include "game/engine.h"

extern int Ov002_GetPhaseWord(void);
extern void INITi_CpuClear32_0x01ff86fc();
extern void Ov002_DrawRecordLine(void *self, void *req);
extern void Ov002_TakeBattleViewFocus(void);
extern void Slot48_StoreAtCurrentIndex(void *self, void *req);

extern unsigned char data_0204c240;

int Ov002_FinishRequest(int *self, char *req) {
    ScriptVm_ReadOperandInt(self, req + 8);

    if (Ov002_GetPhaseWord() == 1 && (data_0204c240 & 4) != 0) {
        return 1;
    }

    INITi_CpuClear32_0x01ff86fc(0, self[0x4a] + 0x4a4, 0x100);
    Ov002_DrawRecordLine(self, req);
    Ov002_TakeBattleViewFocus();
    GameState_SetField(0x20ef, 1, 1);
    Slot48_StoreAtCurrentIndex(self, req);
    return 0;
}
