
#include "nitro/types.h"

typedef struct Ov002PackedTallyPacket {
    u8 nOp;
    u8 bFields;
    s16 aValues[];
} Ov002PackedTallyPacket;
typedef struct Ov002TallyRequest {
    u8 nKind;
    u8 nOwner;
    u16 pad002;
    int nAmount;
} Ov002TallyRequest;
typedef struct Ov002SessionBlock {
    char pad000[0xb9];
    s8 anTallyIds[5];
    char pad0be[0xa];
} Ov002SessionBlock;
typedef struct Ov002RootContext {
    char pad0000[0x8b64];
    u32 dwLeaveFlags;
    char pad8b68[0x64];
    Ov002SessionBlock session;
} Ov002RootContext;
typedef struct Ov002DayClock { u8 nModeFlags; } Ov002DayClock;
typedef struct Ov002TallyRules { char pad000[3]; u8 nTallyLimit; } Ov002TallyRules;

extern Ov002RootContext *data_ov002_0207fa00;
extern Ov002DayClock data_0204c240;
extern Ov002TallyRules data_0204c248;
extern void Ov002_ApplyTally(Ov002TallyRequest *);
extern u32 Session_GetLocalPlayerIndex(void);
extern int Session_IsReady(void);
extern void Ov002_PauseMissionScene(int);

/* Apply flag-selected tally amounts and unpack five three-bit session ids.
 * The payload is halfwords; the optional 32-bit amount is high-half first.
 * nPayloadBytes is part of the dispatch ABI but is not consumed here.
 */
void Ov002_ApplyPackedTallyMessage(Ov002PackedTallyPacket *pPacket, u32 nPayloadBytes)
{
    Ov002TallyRequest request;
    Ov002RootContext *pRoot;
    int nAmount;
    int nCursor;
    int nIndex;
    u16 nPackedIds;
    int nValid;
    s8 *pId;
    int nHigh;
    u32 nLow;

    pRoot = data_ov002_0207fa00;
    nCursor = 0;
    if (pPacket->bFields & 1) {
        request.nKind = 3;
        request.nOwner = 0;
        request.nAmount = pPacket->aValues[nCursor++];
        Ov002_ApplyTally(&request);
    }
    if (pPacket->bFields & 2) {
        nHigh = pPacket->aValues[nCursor];
        nLow = (u16)pPacket->aValues[nCursor + 1];
        request.nKind = 2;
        request.nOwner = 0;
        nAmount = ((u32)nHigh << 16) | nLow;
        request.nAmount = nAmount;
        nCursor += 2;
        Ov002_ApplyTally(&request);
    }
    if (pPacket->bFields & 4) {
        nPackedIds = pPacket->aValues[nCursor++];
        nValid = 0;
        pId = pRoot->session.anTallyIds;
        for (nIndex = 0; nIndex < 5; nIndex++) {
            if (Session_GetLocalPlayerIndex() != 0) {
                *pId = nPackedIds & 7;
                if (*pId == 7) {
                    *pId = -1;
                }
            }
            if (*pId >= 0) {
                nValid++;
            }
            nPackedIds >>= 3;
            pId++;
        }
        if (data_0204c240.nModeFlags & 4) {
            if (data_0204c248.nTallyLimit < nValid && Session_IsReady()) {
                Ov002_PauseMissionScene(0);
                pRoot->dwLeaveFlags |= 0x80000000;
            }
        } else if (data_0204c240.nModeFlags & 2) {
            Ov002_PauseMissionScene(0);
        }
    }
    for (nIndex = 0; nIndex < 4; nIndex++) {
        if (pPacket->bFields & (1 << (nIndex + 3))) {
            request.nKind = 7;
            request.nOwner = nIndex;
            request.nAmount = pPacket->aValues[nCursor++];
            Ov002_ApplyTally(&request);
        }
    }
}
