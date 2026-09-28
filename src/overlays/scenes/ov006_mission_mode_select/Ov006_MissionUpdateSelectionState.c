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

extern MissionContext *data_ov006_020565e4;

extern int Game_PollSceneAlive(void);
extern void Game_ReadLocalProfile(MissionSelectionBuffer *buffer);
extern void StrCopy16(void *selection_block, void *payload);
extern int Ov006_GetPeerTileUploadPending(int value);
extern void Ov006_UploadSlotTiles(int mode, void *send_block, u32 size);
extern void Ov006_MissionUpdateInputTransition(void);
extern void GameSession_SetSyncEnabled(int value);
extern int Ov006_MissionIsTransitionDone(void);
extern int Ov006_SendNetworkPacket(const void *payload, u32 payload_size);
extern void Ov006_UpdateSelectionConfirmationState(void);
extern void Ov006_UpdateAndGetIdleHandler(void);

void *Ov006_MissionUpdateSelectionState(void) {
    MissionSelectionBuffer buffer;
    void *next = 0;

    switch (Game_PollSceneAlive()) {
    case 3:
        break;
    case 4:
        Game_ReadLocalProfile(&buffer);
        StrCopy16(data_ov006_020565e4->selection_block, buffer.payload);
        if (Ov006_GetPeerTileUploadPending(0) != 0) {
            Ov006_UploadSlotTiles(0, &data_ov006_020565e4->flags, 0x68);
            if (data_ov006_020565e4->flags.bits.send_started != 0) {
                Ov006_MissionUpdateInputTransition();
                GameSession_SetSyncEnabled(0);
                next = (void *)Ov006_UpdateSelectionConfirmationState;
                break;
            }
        }
        if (Ov006_MissionIsTransitionDone() != 0) {
            Ov006_SendNetworkPacket(data_ov006_020565e4->selection_block, 0x18);
        }
        break;
    default:
        data_ov006_020565e4->state = 0;
        next = (void *)Ov006_UpdateAndGetIdleHandler;
        break;
    }

    return next;
}
