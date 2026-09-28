#include "nitro/types.h"

#include "game/ov008_camp_menu.h"
/* Synchronises the mission selection confirmations with the peers: sends the local entry, collects
 * theirs and, once every entry is confirmed, starts the lobby transfer. */

typedef void (*MissionCallback)(void);

#define MISSION_CONTEXT (data_ov008_02090f24.pContext)
extern int Ov008_IsSceneState4(void);
extern int Session_IsReady(void);
extern u16 GetGlobalU16At6(void);
extern void Ov008_RefreshSelectionSendBlock(void);
extern int MsgQueue_SendGate(int type, u16 *payload, u16 size);
extern u32 Session_GetLocalPlayerIndex(void);
extern void StoreToGlobalPtr4Field28(int state);
extern void Ov008_MissionIdleStateNoOp(void);
extern void Ov008_MissionLobbyStartTransfer(void);

MissionCallback Ov008_UpdateSelectionConfirmationState(void) {
    MissionCallback nextState = 0;
    int synchronizationComplete = 0;
    MissionContext *context = MISSION_CONTEXT;

    if (context->localMode != 0) {
        synchronizationComplete = 1;
    } else {
        if (Ov008_IsSceneState4() == 0) {
            return Ov008_MissionIdleStateNoOp;
        }

        if (Session_IsReady() != 0) {
            if (MISSION_CONTEXT->entryUpdateMask != 0) {
                u16 sessionMask = GetGlobalU16At6();
                int connectedCount = 0;
                int entryOffset = sizeof(MissionEntry);
                int confirmedCount = 0;
                int playerIndex;

                for (playerIndex = 1; playerIndex < 4;
                     playerIndex++, entryOffset += sizeof(MissionEntry)) {
                    MISSION_CONTEXT->message.selection.peerStatus[playerIndex - 1] = 0;
                    if ((sessionMask & (1 << playerIndex)) != 0) {
                        connectedCount++;
                        if (((MissionEntryFlags *)((u8 *)MISSION_CONTEXT +
                                0x4ad + entryOffset))->confirmed) {
                            confirmedCount++;
                        }
                    }
                }

                if (connectedCount != 0 && connectedCount == confirmedCount) {
                    synchronizationComplete = 1;
                }
                MISSION_CONTEXT->entryUpdateMask = 0;
            }

            Ov008_RefreshSelectionSendBlock();
            context = MISSION_CONTEXT;
            context->message.selection.flags.bits.sendStarted = 1;
            MsgQueue_SendGate(0xd, (u16 *)&MISSION_CONTEXT->message.selection,
                          sizeof(MissionSelectionSendBlock));
        } else {
            u32 playerIndex;

            context = MISSION_CONTEXT;
            playerIndex = Session_GetLocalPlayerIndex();
            if (!context->liveEntries.entries[playerIndex].flags.confirmed) {
                context->localEntry.flags.confirmed = 1;
                MISSION_CONTEXT->localEntry.playerIndex =
                    (u8)Session_GetLocalPlayerIndex();
                MsgQueue_SendGate(0xd,
                              (u16 *)&MISSION_CONTEXT->localEntry,
                              sizeof(MissionEntry));
            } else {
                context->messageHandle = 0xffff;
                synchronizationComplete = 1;
            }
        }
    }

    if (synchronizationComplete != 0) {
        StoreToGlobalPtr4Field28(1);
        nextState = Ov008_MissionLobbyStartTransfer;
    }
    return nextState;
}
