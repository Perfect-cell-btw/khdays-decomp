/* Enters the ov008 result/continue screen: refresh panels, honor the session, seed the menu
 * context, and pick the next scene callback by whether a pending job is still running.
 *
 * Gets the local player's slot record (Slot4_GetIfOccupied of the session index), rebuilds two panels,
 * and if a session exists re-arms it. With a slot record, runs PartyState_ResetBuffers and pushes the record's
 * field +4. Then, if Ov008_Link_IsLocal reports no pending job, clears the menu context's counters
 * (either just +0x172, or the +0x92..+0x9e block when Ov008_IsSessionReady is set) and returns the
 * "ready" callback; otherwise returns the "wait" callback.
 */

#include "game/engine.h"

typedef void (*SceneCallback)(void);

extern int Slot4_GetIfOccupied(unsigned int index);
extern void Ov008_SetupMenuDisplay(void);
extern void Ov008_LoadMenuUi(void);
extern void Ov008_ResetPartyMemberAndLayout(int value, int b);
extern void Ov008_RefreshGameplayRulesFromState(void);
extern int Ov008_Link_IsLocal(void);
extern int Ov008_IsSessionReady(void);
extern void Ov008_CommitSynchronizedSnapshotState(void);
extern int *data_ov008_02090f00;
extern void Ov008_TransferSessionSnapshotState(void);

SceneCallback Ov008_RefreshAndPickScene(void) {
    int record = Slot4_GetIfOccupied((unsigned int)Session_GetLocalPlayerIndex());

    Ov008_SetupMenuDisplay();
    Ov008_LoadMenuUi();
    if (Session_Exists()) {
        GameSession_SetSyncEnabled(1);
    }
    if (record != 0) {
        PartyState_ResetBuffers();
        Ov008_ResetPartyMemberAndLayout(*(int *)(record + 4), 0);
    }
    Ov008_RefreshGameplayRulesFromState();
    if (Ov008_Link_IsLocal() != 0) {
        return Ov008_CommitSynchronizedSnapshotState;
    }
    if (Ov008_IsSessionReady() != 0) {
        *(unsigned short *)((int)data_ov008_02090f00 + 0x92) = 0;
        *(unsigned short *)((int)data_ov008_02090f00 + 0x96) = 0;
        *(unsigned short *)((int)data_ov008_02090f00 + 0x9a) = 0;
        *(unsigned short *)((int)data_ov008_02090f00 + 0x9e) = 0;
    } else {
        *(unsigned short *)((int)data_ov008_02090f00 + 0x172) = 0;
    }
    return Ov008_TransferSessionSnapshotState;
}
