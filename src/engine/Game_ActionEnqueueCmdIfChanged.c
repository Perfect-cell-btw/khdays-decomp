/*
 * Game_ActionEnqueueCmdIfChanged - action-command handler (opcode table data_020425ec). Reads a
 * command id (cmd[0]) and an argument (cmd[4]) from the command stream. If the id differs from the
 * last one enqueued (the signed-byte global data_020425e8), it is dispatched to one of two queues
 * and recorded as the new last id:
 *   - ids in {1,6,8,0xa,0xc,0xe,0x11,0x22} go to SoundMgr_SwitchBgmResume;
 *   - every other id goes to SoundMgr_SwitchBgm.
 * Both queues receive (id & 0xff, arg). When the id is unchanged nothing happens. Returns 1.
 *
 * THUMB. The last-id global is read signed (ldrsb) and rewritten as a byte; the id byte is
 * materialised with the lsl#24/lsr#24 zero-extend pair, i.e. (unsigned char)id.
 */

#include "nitro/types.h"

extern int  ScriptVm_ReadOperandInt(int st, u16 *cmd);   /* ScriptVm_ReadOperandInt */
extern void SoundMgr_SwitchBgmResume(int id, int arg);
extern void SoundMgr_SwitchBgm(int id, int arg);
extern char data_020425e8;                      /* last enqueued command id */

int Game_ActionEnqueueCmdIfChanged(int param_1, u16 *param_2)
{
    int uVar1 = ScriptVm_ReadOperandInt(param_1, param_2);
    int uVar2 = ScriptVm_ReadOperandInt(param_1, param_2 + 4);
    if (uVar1 != data_020425e8) {
        if (uVar1 == 1 || uVar1 == 6 || uVar1 == 8 || uVar1 == 0xa ||
            uVar1 == 0xc || uVar1 == 0xe || uVar1 == 0x11 || uVar1 == 0x22) {
            SoundMgr_SwitchBgmResume((unsigned char)uVar1, uVar2);
        } else {
            SoundMgr_SwitchBgm((unsigned char)uVar1, uVar2);
        }
        data_020425e8 = (char)uVar1;
    }
    return 1;
}
