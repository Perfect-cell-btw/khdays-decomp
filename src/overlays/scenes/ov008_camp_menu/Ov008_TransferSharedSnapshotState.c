/* Sends the shared snapshot in chunks as the slowest peer acknowledges them (host) or collects it
 * (clients), then commits it. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ov008MessageHeader {
    u8 messageType : 4;
    u8 sessionState : 4;
    u8 playerIndex;
} Ov008MessageHeader;

typedef struct Ov008Message68 {
    Ov008MessageHeader header;
    u16 chunkIndex;
    u8 payload[64];
} Ov008Message68;

typedef struct Ov008TransferState {
    Ov008MessageHeader header;
    u16 nextChunk;
} Ov008TransferState;

typedef struct Ov008SharedSnapshot {
    u8 bytes[0x444];
} Ov008SharedSnapshot;

typedef struct Ov008MenuContext {
    u8 pad_0000[0x10];
    u32 commonTransferReady;
    u8 pad_0014[4];
    u32 sessionState;
    Ov008MessageHeader outgoing9;
    Ov008MessageHeader peerHeaders[4];
    u8 pad_0026[0x26];
    Ov008Message68 outgoing8;
    Ov008TransferState playerTransfer[4];
    u8 pad_00a0[0xd0];
    Ov008TransferState commonTransfer;
    u8 pad_0174[4];
    Ov008SharedSnapshot sharedSnapshot;
} Ov008MenuContext;

extern Ov008MenuContext *data_ov008_02090f00;

extern u32 Ov008_GetSlotPresenceMask(void);
extern void Ov008_UpdateCursorSprite(void);
extern int Ov008_IsSessionReady(void);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void Ov008_SendMenuMessage(u8 messageType);
extern void Ov008_CommitSynchronizedSnapshotState(void);

void *Ov008_TransferSharedSnapshotState(void)
{
    u32 playerMask = Ov008_GetSlotPresenceMask();

    data_ov008_02090f00->sessionState = 6;
    Ov008_UpdateCursorSprite();

    if (Ov008_IsSessionReady() != 0) {
        u32 i;
        u32 minChunk;
        Ov008MenuContext *context;

        context = data_ov008_02090f00;
        minChunk = 0xffff;
        i = 1;

        do {
            if ((playerMask & (1 << i)) != 0 &&
                (minChunk == 0xffff ||
                 context->playerTransfer[i].nextChunk < minChunk)) {
                minChunk = context->playerTransfer[i].nextChunk;
            }
            i++;
        } while ((int)i < 4);

        if (minChunk < 0x12) {
            u32 offset;
            u32 remaining;
            u16 copySize = 0x40;
            u8 *source;
            u8 *destination;

            context->outgoing8.chunkIndex = (u16)minChunk;
            context = data_ov008_02090f00;
            offset = (u16)(context->outgoing8.chunkIndex << 6);
            source = context->sharedSnapshot.bytes;
            destination = context->outgoing8.payload;
            remaining = sizeof(context->sharedSnapshot) - offset;
            if (remaining < 0x40) {
                copySize = (u16)remaining;
            }
            MI_CpuCopy8(source + offset, destination, copySize);
            Ov008_SendMenuMessage(8);
        }

        context = data_ov008_02090f00;
        i = 1;
        do {
            if ((playerMask & (1 << i)) != 0 &&
                context->peerHeaders[i].sessionState != 7) {
                return 0;
            }
            i++;
        } while ((int)i < 4);
        return (void *)Ov008_CommitSynchronizedSnapshotState;
    }

    {
        Ov008MenuContext *context = data_ov008_02090f00;

        if (context->peerHeaders[0].sessionState < 6) {
            Ov008_SendMenuMessage(9);
            return 0;
        }
        if (context->commonTransfer.nextChunk <= 0x12) {
            if (context->commonTransferReady == 0) {
                Ov008_SendMenuMessage(9);
            } else {
                context->commonTransferReady = 0;
                Ov008_SendMenuMessage(4);
            }
        }
        return data_ov008_02090f00->commonTransfer.nextChunk >= 0x12
                   ? (void *)Ov008_CommitSynchronizedSnapshotState
                   : 0;
    }
}
