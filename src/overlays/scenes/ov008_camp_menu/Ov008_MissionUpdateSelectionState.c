typedef unsigned char u8;
typedef unsigned int u32;

typedef union {
    u8 raw;
    struct {
        u8 send_started : 1;
        u8 unused : 7;
    } bits;
} MissionFlags;

typedef struct {
    u8 pad_000[0x2c];
    u32 state;
    u8 pad_030[0x3e4];
    u8 selection_block[0x18];
    MissionFlags flags;
    u8 send_block[0x67];
} MissionContext;

typedef struct {
    u32 header;
    u8 payload[0x50];
} MissionSelectionBuffer;

extern MissionContext *data_ov008_02090f24;

extern int Game_PollSceneAlive(void);
extern void Game_ReadLocalProfile(MissionSelectionBuffer *buffer);
extern void StrCopy16(void *selection_block, void *payload);
extern int Ov008_GetPeerTileUploadPending(int value);
extern void Ov008_UploadSlotTiles(int mode, void *send_block, u32 size);
extern void Ov008_MissionUpdateInputTransition(void);
extern void GameSession_SetSyncEnabled(int value);
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
        StrCopy16(data_ov008_02090f24->selection_block, buffer.payload);
        if (Ov008_GetPeerTileUploadPending(0) != 0) {
            Ov008_UploadSlotTiles(0, &data_ov008_02090f24->flags, 0x68);
            if (data_ov008_02090f24->flags.bits.send_started != 0) {
                Ov008_MissionUpdateInputTransition();
                GameSession_SetSyncEnabled(0);
                next = (void *)Ov008_UpdateSelectionConfirmationState;
                break;
            }
        }
        if (Ov008_MissionIsTransitionDone() != 0) {
            Ov008_SendPacket(data_ov008_02090f24->selection_block, 0x18);
        }
        break;
    default:
        data_ov008_02090f24->state = 0;
        next = (void *)Ov008_MissionIdleStateNoOp;
        break;
    }

    return next;
}
