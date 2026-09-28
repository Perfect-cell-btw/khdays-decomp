#pragma opt_dead_assignments off
/* Ov006_MissionPeerSyncState -- synchronize Mission Mode peer names and
 * presence latches while the scene connection state advances. */
#include "nitro/types.h"
typedef void (*MissionCallback)(void);

typedef struct {
    u16 name[11];
    u8 status;
    u8 reserved;
} MissionPeerRecord;

typedef union {
    MissionPeerRecord all[4];
    struct {
        MissionPeerRecord local;
        MissionPeerRecord remote[3];
    } split;
} MissionPeerRecords;

typedef struct {
    u8 flags;
    u8 reserved01[3];
    u32 sessionValue;
    u16 sessionMask;
    u16 playerNames[4][11];
    u8 peerStatus[4];
    u8 reserved66[2];
} MissionSelectionSendBlock;

typedef struct {
    u8 pad_000[0x28];
    u32 transitionRequested;
    u32 sendBusy;
    u8 pad_030[0x10];
    u8 remotePeerCapacity;
    u8 pad_041[3];
    MissionPeerRecords records;
    u8 remotePeerActive[3];
    u8 pad_0a7[0x385];
    MissionSelectionSendBlock selectionSendBlock;
    u32 refreshRequested;
} MissionContext;

typedef struct {
    u32 header;
    u8 payload[0x50];
} MissionSelectionBuffer;

extern MissionContext *data_ov008_02090f24;
extern u16 data_ov008_02090f40[];

extern int Game_PollSceneAlive(void);
extern void Ov105_SetParamWord8(u32 value);
extern void Game_ReadLocalProfile(MissionSelectionBuffer *buffer);
extern u16 *StrCopy16(u16 *dst, const u16 *src);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void Ov105_WH_StartMeasureChannel(void);
extern void Ov008_MissionStartTransition(void);
extern u16 func_01ff8138(void);
extern int Ov008_GetPeerTileUploadPending(int peerIndex);
extern void Ov008_UploadSlotTiles(int peerIndex, u16 *name, u32 size);
extern void MI_CpuFill8(void *dst, int value, u32 size);
extern void Ov008_RefreshSelectionSendBlock(void);
extern int Ov008_MissionIsTransitionDone(void);
extern int Ov008_SendPacket(const void *payload, u32 payloadSize);
extern void Ov008_MissionIdleStateNoOp(void);

MissionCallback Ov008_MissionPeerSyncState(void) {
    MissionSelectionBuffer localProfile;
    MissionCallback nextState = 0;

    switch (Game_PollSceneAlive()) {
    case 1: {
        MissionContext *context;

        Ov105_SetParamWord8(0x800356);
        context = data_ov008_02090f24;
        Game_ReadLocalProfile(&localProfile);
        StrCopy16(context->records.split.local.name,
                      (u16 *)localProfile.payload);
        *(u16 *)&context->records.split.local.status = 1;
        data_ov008_02090f24->remotePeerCapacity = 3;
        MI_CpuCopy8(&data_ov008_02090f24->records.split.local,
                    data_ov008_02090f40, sizeof(MissionPeerRecord));
        Ov105_WH_StartMeasureChannel();
        break;
    }
    case 3:
        break;
    case 7:
        Ov008_MissionStartTransition();
        break;
    case 4: {
        u16 sessionMask;
        u8 *remotePeerActive;
        u32 peerIndex;
        int remoteIndex;

        peerIndex = 0;
        remotePeerActive = 0;
        remotePeerActive = data_ov008_02090f24->remotePeerActive;
        sessionMask = func_01ff8138();

        peerIndex = 1;
        goto check_peer;
    process_peer:
        {
            if (Ov008_GetPeerTileUploadPending(peerIndex) != 0) {
                Ov008_UploadSlotTiles(
                    peerIndex,
                    data_ov008_02090f24->records.split.remote[peerIndex - 1].name,
                    sizeof(MissionPeerRecord));
                remoteIndex = peerIndex - 1;
                remotePeerActive[remoteIndex] = 1;
                data_ov008_02090f24->transitionRequested = 1;
                data_ov008_02090f24->sendBusy = 0;
            } else {
                remoteIndex = peerIndex - 1;
                if (remotePeerActive[remoteIndex] != 0 &&
                    (sessionMask & (1 << peerIndex)) == 0) {
                    remotePeerActive[remoteIndex] = 0;
                data_ov008_02090f24->selectionSendBlock.peerStatus[peerIndex] = 0;
                MI_CpuFill8(
                    data_ov008_02090f24->selectionSendBlock.playerNames[peerIndex],
                    0, sizeof(data_ov008_02090f24->selectionSendBlock.playerNames[0]));
                MI_CpuFill8(
                    &data_ov008_02090f24->records.split.remote[peerIndex - 1], 0,
                    sizeof(MissionPeerRecord));
                    data_ov008_02090f24->refreshRequested = 1;
                }
            }
            peerIndex = (u8)(peerIndex + 1);
        }
    check_peer:
        if (peerIndex < 4) {
            goto process_peer;
        }

        Ov008_RefreshSelectionSendBlock();
        if (Ov008_MissionIsTransitionDone() != 0) {
            Ov008_SendPacket(
                &data_ov008_02090f24->selectionSendBlock,
                sizeof(MissionSelectionSendBlock));
        }
        break;
    }
    default:
        data_ov008_02090f24->sendBusy = 0;
        nextState = Ov008_MissionIdleStateNoOp;
        break;
    }

    return nextState;
}