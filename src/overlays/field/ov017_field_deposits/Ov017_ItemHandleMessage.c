/* Ov017_ItemHandleMessage -- Ov017_ItemHandleMessage: the item piece's message handler, switching
 * on the message type byte.  Type 1: keeps the spawn id that came back (+0x1b9).  Type 2 (a
 * player took it): enters the given state (Ov017_ItemBeginGiven 020804d4: state 5, timer 0),
 * leaves the room (bit 3 of +0x12) and records the player (+0x1b8).  Type 3 (hand the item
 * over): inside a running scene (ov002 0206b758) -- and on a peer only when the recorded
 * player is the local one (01fffe14) -- looks the item key (+0x1b6) up (ov002 0206d144 /
 * 0206d194) and calls the player's actor sub-object hook at +0x1bc (actor from 01fffde0, sub
 * at +0x4ec) with the spawn id, the entry's low flag byte (+0x42) and its key (+0x40).  Type
 * 4: state 7 (done).  Type 0 and anything above 4 do nothing. */

#include "nitro/types.h"

typedef struct Ov017ItemMessage {
    u8   nType;               /* 0x00 */
    u8   pad_01[3];
    union {
        char nSpawnId;        /* 0x04: type 1 */
        u8   nPlayer;         /* 0x04: type 2 */
    } u;
} Ov017ItemMessage;

typedef struct Ov017Item {
    u8   pad_000[0x12];
    u16  nPieceFlags;         /* 0x012: bit 3 = in the room */
    u8   pad_014[0x1b4 - 0x14];
    u8   nState;              /* 0x1b4 */
    u8   pad_1b5;
    short nItemKey;           /* 0x1b6 */
    u8   nPlayer;             /* 0x1b8 */
    char nSpawnId;            /* 0x1b9 */
} Ov017Item;

typedef struct Ov017KeyEntry {
    u8   pad_00[0x40];
    u16  nKey;                /* 0x40 */
    short nFlags;             /* 0x42 */
} Ov017KeyEntry;

typedef struct Ov017PlayerSub {
    u8   pad_000[0x1bc];
    void (*pfnGiveItem)(struct Ov017PlayerSub *pSub, int nSpawnId, int nFlags, int nKey); /* 0x1bc */
} Ov017PlayerSub;

typedef struct Ov017PlayerActor {
    u8   pad_000[0x4ec];
    Ov017PlayerSub *pSub;     /* 0x4ec */
} Ov017PlayerActor;

extern void  Ov017_ResetState5(Ov017Item *pSelf);                   /* Ov017_ItemBeginGiven */
extern int   Ov002_IsSessionOpen(void);                               /* scene running? */
extern int   Session_GetLocalPlayerIndex(void);                                     /* Session_GetLocalPlayerIndex */
extern int   QueryActiveStateOrDelegate(void);                                     /* the local peer */
extern Ov017PlayerActor *GetEntryField20ByIndex(int nPlayer);                  /* the player's actor */
extern int   Ov002_FindKeyEntryIndex(int nKey);                         /* key -> entry index */
extern Ov017KeyEntry *Ov002_GetRootField8d14(int nIndex);              /* entry index -> entry */

void Ov017_ItemHandleMessage(Ov017Item *pSelf, Ov017ItemMessage *pMessage)
{
    Ov017PlayerActor *pActor;
    Ov017KeyEntry *pEntry;
    int nFlags;
    int nKey;
    u8 nSpawn;

    switch (pMessage->nType) {
    case 0:
        break;
    case 1:
        pSelf->nSpawnId = pMessage->u.nSpawnId;
        break;
    case 2:
        Ov017_ResetState5(pSelf);
        pSelf->nPieceFlags &= ~8;
        pSelf->nPlayer = pMessage->u.nPlayer;
        break;
    case 3:
        if (Ov002_IsSessionOpen() == 0) {
            break;
        }
        if (Session_GetLocalPlayerIndex() != 0 && pSelf->nPlayer != QueryActiveStateOrDelegate()) {
            break;
        }
        pActor = GetEntryField20ByIndex(pSelf->nPlayer);
        pEntry = Ov002_GetRootField8d14((short)(Ov002_FindKeyEntryIndex((short)pSelf->nItemKey)));
        nSpawn = pSelf->nSpawnId;
        nFlags = pEntry->nFlags & 0xff;
        nKey = pEntry->nKey;
        if (pActor->pSub->pfnGiveItem != 0) {
            pActor->pSub->pfnGiveItem(pActor->pSub, nSpawn, nFlags, nKey);
        }
        break;
    case 4:
        pSelf->nState = 7;
        break;
    }
}
