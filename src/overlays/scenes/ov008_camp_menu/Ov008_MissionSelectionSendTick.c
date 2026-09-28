/* Sends the mission selection to the peers: sets the wireless entry, refreshes the send block and
 * sends it once the transition is done; returns the next state. */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 sendStarted : 1;
    u8 changed : 1;
    u8 unused : 6;
} MissionSelectionSendFlags;

typedef struct {
    MissionSelectionSendFlags flags;
    u8 reserved01[3];
    u32 sessionValue;
    unsigned short sessionMask;
    unsigned short playerNames[4][11];
    u8 peerStatus[4];
    u8 reserved66[2];
} MissionSelectionSendBlock;

typedef struct {
    u8 pad_000[0x2c];
    u32 sendBusy;
    u8 pad_030[0x3fc];
    MissionSelectionSendBlock selectionSendBlock;
    u8 pad_494[0x0c];
    u32 entryUpdateMask;
    u8 pad_4a4[0x44];
    u32 exitRequested;
} MissionContext;

extern int data_ov008_02090f24;
#define CONTEXT (*(MissionContext **)&data_ov008_02090f24)
extern int Ov105_WM_SetEntry();
extern int Ov008_IsSceneState4(void);
extern void Ov008_RefreshSelectionSendBlock(void);
extern int Ov008_MissionIsTransitionDone(void);
extern int Ov008_SendPacket(const void *payload, u32 payloadSize);
extern void Ov008_MissionIdleStateNoOp(void);
extern void Ov008_MissionMenuOpenTick(void);

int Ov008_MissionSelectionSendTick(void)
{
    int zero = 0;
    int nextState = zero;

    if (CONTEXT->exitRequested != zero) {
        nextState = (int)Ov008_MissionMenuOpenTick;
        CONTEXT->sendBusy = zero;
    } else {
        if (!CONTEXT->selectionSendBlock.flags.sendStarted) {
            if (Ov105_WM_SetEntry(zero, zero) == zero) {
                return nextState;
            }
        }
        if (Ov008_IsSceneState4() == zero) {
            return (int)Ov008_MissionIdleStateNoOp;
        }
        Ov008_RefreshSelectionSendBlock();
        CONTEXT->selectionSendBlock.flags.sendStarted = 1;
        if (Ov008_MissionIsTransitionDone() != zero) {
            if (Ov008_SendPacket(
                    &CONTEXT->selectionSendBlock,
                    sizeof(MissionSelectionSendBlock)) != zero) {
                CONTEXT->entryUpdateMask = zero;
                nextState = (int)Ov008_MissionMenuOpenTick;
            }
        }
    }
    return nextState;
}
