/* Ov106_CmdSaveGame -- Ov106_CmdSaveGame: script command that walks the ov002 save sequence,
 * keeping its step in data_ov106_020b8b64: 0 waits for 0206d324, 1 for 0206d350, 2 requests
 * the write (02071de4 1), 3 waits for it (02071e08) and then finishes (02073ffc 1 / 1), resets
 * the step and returns 1; until then 0. *
 * PROVENANCE: byte-identical twin of ov023's Ov023_CmdSaveGame (Ov023_CmdSaveGame), same code and
 * callees, verified byte-exact in this overlay. */
extern int  Ov002_TakeSessionPhase(void);
extern int  Ov002_MuteEntryAndParkSession(void);
extern void Ov002_Link_RequestSave(int nArg);
extern int  Ov002_StepPeerObjectLoading(void);
extern void Ov002_FireSlotHook(int nA, int nB);
extern int  data_ov106_020b8b64;                                    /* the save step */

int Ov106_CmdSaveGame(void)
{
    switch (data_ov106_020b8b64) {
    case 0:
        if (Ov002_TakeSessionPhase() != 0) {
            data_ov106_020b8b64++;
        }
        break;
    case 1:
        if (Ov002_MuteEntryAndParkSession() != 0) {
            data_ov106_020b8b64++;
        }
        break;
    case 2:
        Ov002_Link_RequestSave(1);
        data_ov106_020b8b64++;
        break;
    case 3:
        if (Ov002_StepPeerObjectLoading() != 0) {
            Ov002_FireSlotHook(1, 1);
            data_ov106_020b8b64 = 0;
            return 1;
        }
        break;
    }
    return 0;
}
