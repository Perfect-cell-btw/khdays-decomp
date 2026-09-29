#include "nitro/types.h"

#include "game/ov008_camp_menu.h"
#include "game/engine.h"
typedef struct {
    u32 header;
    u8 payload[0x50];
} MissionSelectionBuffer;

#define MISSION_CONTEXT (data_ov008_02090f24.pContext)

extern void Game_ReadLocalProfile(MissionSelectionBuffer *buffer);
extern void StrCopy16(void *selection_block, void *payload);
extern int Ov008_GetPeerTileUploadPending(int value);
extern void Ov008_UploadSlotTiles(int mode, void *send_block, u32 size);
extern void Ov008_MissionUpdateInputTransition(void);
extern int Ov008_MissionIsTransitionDone(void);
extern int Ov008_SendPacket(const void *payload, u32 payload_size);
extern void Ov008_UpdateSelectionConfirmationState(void);
extern void Ov008_MissionIdleStateNoOp(void);

void *Ov008_MissionUpdateSelectionState(void) {
    MissionSelectionBuffer buffer;
    void *next = 0;

    switch (Game_PollSceneAlive()) {
    case 3:
        break;
    case 4:
        Game_ReadLocalProfile(&buffer);
        StrCopy16(MISSION_CONTEXT->selectionBlock, buffer.payload);
        if (Ov008_GetPeerTileUploadPending(0) != 0) {
            Ov008_UploadSlotTiles(0, &MISSION_CONTEXT->message.selection.flags, 0x68);
            if (MISSION_CONTEXT->message.selection.flags.bits.sendStarted != 0) {
                Ov008_MissionUpdateInputTransition();
                GameSession_SetSyncEnabled(0);
                next = (void *)Ov008_UpdateSelectionConfirmationState;
                break;
            }
        }
        if (Ov008_MissionIsTransitionDone() != 0) {
            Ov008_SendPacket(MISSION_CONTEXT->selectionBlock, 0x18);
        }
        break;
    default:
        MISSION_CONTEXT->sendBusy = 0;
        next = (void *)Ov008_MissionIdleStateNoOp;
        break;
    }

    return next;
}
