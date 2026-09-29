#include "nitro/types.h"

#include "game/ov006_mission_mode_select.h"
#include "game/engine.h"

/* Synchronises the mission selection confirmations with the peers: once every connected peer has
 * confirmed (or on a forced exit), moves on to syncing the entries. */

typedef void (*MissionCallback)(void);

#define MISSION_CONTEXT (data_ov006_020565e4.pContext)
extern int Ov006_IsSceneState4(void);
extern void Ov006_RefreshSelectionSendBlock(void);
extern void Ov006_UpdateAndGetIdleHandler(void);
extern void Ov006_SynchronizeMissionEntries(void);

MissionCallback Ov006_UpdateSelectionConfirmationState(void) {
    MissionCallback nextState = 0;
    int synchronizationComplete = 0;
    MissionContext *context = MISSION_CONTEXT;

    if (context->localMode != 0) {
        synchronizationComplete = 1;
    } else {
        if (Ov006_IsSceneState4() == 0) {
            return Ov006_UpdateAndGetIdleHandler;
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

            Ov006_RefreshSelectionSendBlock();
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
        nextState = Ov006_SynchronizeMissionEntries;
    }
    return nextState;
}
