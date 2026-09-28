#include "nitro/types.h"

#include "game/ov008_camp_menu.h"
/* Synchronises the mission selection confirmations with the peers: sends the local entry, collects
 * theirs and, once every entry is confirmed, starts the lobby transfer. */

typedef void (*MissionCallback)(void);

typedef struct {
    u8 selectable : 1;
    u8 request : 1;
    u8 confirmed : 1;
    u8 acknowledged : 1;
    u8 unused : 4;
} MissionEntryFlags;

typedef struct {
    u8 playerIndex;
    MissionEntryFlags flags;
    s8 characterId;
    u8 reserved;
    u16 missionId;
} MissionEntry;

typedef struct {
    u32 locked : 1;
    u32 unused : 31;
    MissionEntry entries[4];
} MissionEntryBlock;

typedef struct {
    u8 sendStarted : 1;
    u8 unused : 7;
} MissionSendFlags;

typedef struct {
    MissionSendFlags flags;
    u8 pad_01[0x60];
    u8 peerStatus[4];
    u8 pad_65[3];
} MissionSendBlock;

typedef struct {
    u8 pad_000[0x42c];
    MissionSendBlock sendBlock;
    u8 pad_494[0x0c];
    u32 entryUpdateMask;
    u32 entryInputReady;
    MissionEntryBlock liveEntries;
    MissionEntryBlock sentEntries;
    MissionEntry localEntry;
    u8 pad_4e6[2];
    u32 exitRequested;
    u16 messageHandle;
} MissionContext;

#define MISSION_CONTEXT ((MissionContext *)data_ov008_02090f24.pContext)
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

    if (context->exitRequested != 0) {
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
                    MISSION_CONTEXT->sendBlock.peerStatus[playerIndex] = 0;
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
            context->sendBlock.flags.sendStarted = 1;
            MsgQueue_SendGate(0xd, (u16 *)&MISSION_CONTEXT->sendBlock,
                          sizeof(MissionSendBlock));
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
