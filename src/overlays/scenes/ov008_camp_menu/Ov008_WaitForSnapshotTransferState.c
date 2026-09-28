/* Waits for the peers to be ready for the snapshot transfer (host) or for the host's start
 * (clients), then starts the shared snapshot transfer. */

#include "nitro/types.h"

typedef struct Ov008MessageHeader {
    u8 messageType : 4;
    u8 sessionState : 4;
    u8 playerIndex;
} Ov008MessageHeader;

typedef struct Ov008TransferState {
    Ov008MessageHeader header;
    u16 nextChunk;
} Ov008TransferState;

typedef struct Ov008MenuContext {
    u8 pad_0000[0x18];
    u32 sessionState;
    Ov008MessageHeader outgoing9;
    Ov008MessageHeader peerHeaders[4];
    u8 pad_0026[0x6a];
    Ov008TransferState playerTransfer[4];
    u8 pad_00a0[0xd0];
    Ov008TransferState commonTransfer;
} Ov008MenuContext;

extern Ov008MenuContext *data_ov008_02090f00;

extern void Ov008_UpdateCursorSprite(void);
extern int Ov008_IsSessionReady(void);
extern void Ov008_SendMenuMessage(u8 messageType);
extern u32 Ov008_GetSlotPresenceMask(void);
extern void Ov008_TransferSharedSnapshotState(void);

void *Ov008_WaitForSnapshotTransferState(void)
{
    data_ov008_02090f00->sessionState = 5;
    Ov008_UpdateCursorSprite();

    if (Ov008_IsSessionReady() != 0) {
        u32 playerMask;
        u32 i;

        Ov008_SendMenuMessage(9);
        playerMask = Ov008_GetSlotPresenceMask();
        i = 1;
        do {
            if ((playerMask & (1 << i)) != 0 &&
                data_ov008_02090f00->peerHeaders[i].sessionState < 6) {
                return 0;
            }
            i++;
        } while ((int)i < 4);

        data_ov008_02090f00->playerTransfer[0].nextChunk = 0;
        data_ov008_02090f00->playerTransfer[1].nextChunk = 0;
        data_ov008_02090f00->playerTransfer[2].nextChunk = 0;
        data_ov008_02090f00->playerTransfer[3].nextChunk = 0;
        return (void *)Ov008_TransferSharedSnapshotState;
    }

    if (data_ov008_02090f00->peerHeaders[0].sessionState >= 5) {
        Ov008TransferState *transfer =
            &data_ov008_02090f00->commonTransfer;
        transfer->nextChunk = 0;
        return (void *)Ov008_TransferSharedSnapshotState;
    }
    return 0;
}
