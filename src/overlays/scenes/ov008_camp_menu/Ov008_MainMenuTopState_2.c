/* Menu top state: updates the cursor and either commits the selected page locally or exchanges the
 * player records with the peers before entering it. */

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

typedef struct Ov008Message28 {
    Ov008MessageHeader header;
    u8 payload[26];
} Ov008Message28;

typedef struct Ov008MenuContext {
    u8 pad_0000[8];
    u32 playerRecordsReady;
    u8 pad_000c[0xc];
    u32 sessionState;
    Ov008MessageHeader outgoing9;
    Ov008MessageHeader peerHeaders[4];
    u8 pad_0026[0x6a];
    Ov008TransferState playerTransfer[4];
    Ov008Message28 peerRecords[4];
    Ov008Message28 outgoingRecord;
} Ov008MenuContext;

extern u32   Session_GetLocalPlayerIndex(void);
extern u32   Ov008_GetPlayerMask(void);
extern void  Ov008_UpdateCursorSprite(void);
extern int   Ov008_Link_IsLocal(void);
extern int   Ov008_IsSessionReady(void);
extern void  Ov008_SendMenuMessage(u8 messageType);
extern void  Ov008_CommitSelectedPage(void);
extern void  Ov008_EnterSelectedPage(void);
extern Ov008MenuContext *data_ov008_02090f00;

void *Ov008_MainMenuTopState_2(void)
{
    void *result;
    u32 playerMask;

    Session_GetLocalPlayerIndex();
    result = 0;
    playerMask = Ov008_GetPlayerMask();
    Ov008_UpdateCursorSprite();
    data_ov008_02090f00->sessionState = 1;

    if (Ov008_Link_IsLocal() != 0) {
        data_ov008_02090f00->peerRecords[0] =
            data_ov008_02090f00->outgoingRecord;
        return (void *)Ov008_CommitSelectedPage;
    }

    if (Ov008_IsSessionReady() != 0) {
        Ov008MenuContext *context = data_ov008_02090f00;
        if (context->playerRecordsReady == 0) {
            Ov008_SendMenuMessage(9);
        } else {
            u32 i;
            context->playerRecordsReady = 0;
            Ov008_SendMenuMessage(5);
            context = data_ov008_02090f00;
            i = 1;
            do {
                if ((playerMask & (1 << i)) != 0 &&
                    context->playerTransfer[i].nextChunk < 1) {
                    return 0;
                }
                i++;
            } while ((int)i < 4);

            data_ov008_02090f00->peerRecords[0] =
                data_ov008_02090f00->outgoingRecord;
            result = (void *)Ov008_EnterSelectedPage;
        }
    } else {
        u32 peerCount = data_ov008_02090f00->peerHeaders[0].sessionState;
        if (peerCount < 1) {
            Ov008_SendMenuMessage(9);
            return result;
        }
        if (peerCount >= 2) {
            result = (void *)Ov008_EnterSelectedPage;
        } else {
            Ov008_SendMenuMessage(1);
        }
    }
    return result;
}
