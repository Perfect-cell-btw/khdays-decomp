/* Ov017_ItemGivenStep -- Ov017_ItemGivenStep: state function of an item that a player has
 * taken.  The timer (+0x1b0) advances by the frame delta (ov002 0207687c).  In state 5, at
 * 0xc000, the piece moves to state 6 and the host (02030788 == 0), inside a running scene
 * (ov002 0206b758), hands the item over: in a session (02030670) by queueing a type-3
 * message (kind 4, the peers' handlers do the rest), otherwise by calling the player's actor
 * sub-object hook at +0x1bc directly with the spawn id, the key entry's low flag byte (+0x42)
 * and its key (+0x40) (entry from ov002 0206d144 / 0206d194 on the item key +0x1b6).  At
 * 0x1d000 the item is spent: bit 1 of its GameState field is set, its taken field / bit
 * (+0x1ba / +0x1bc) written 1, the piece retired (ov002 02076bd8), state 7, the host queues
 * a type-4 message and the terminal state (ov002 0207cea4) is returned.  Otherwise 0. */

#include "nitro/types.h"

typedef struct Ov017ItemMessage {
    u8   nType;               /* 0x00 */
    u8   pad_01[3];
} Ov017ItemMessage;

typedef struct Ov017Item {
    u8   pad_000[0x14];
    u16  nStateField;         /* 0x014: GameState field */
    u8   nStateBit;           /* 0x016 */
    u8   pad_017[0x1b0 - 0x17];
    int  nTimer;              /* 0x1b0 */
    u8   nState;              /* 0x1b4 */
    u8   pad_1b5;
    short nItemKey;           /* 0x1b6 */
    u8   nPlayer;             /* 0x1b8 */
    char nSpawnId;            /* 0x1b9 */
    u16  nTakenField;         /* 0x1ba */
    u8   nTakenBit;           /* 0x1bc */
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

extern int   Ov002_GetModuleScale(void);                               /* frame delta */
extern int   Session_GetLocalPlayerIndex(void);                                     /* Session_GetLocalPlayerIndex */
extern int   Ov002_IsSessionOpen(void);                               /* scene running? */
extern Ov017PlayerActor *GetEntryField20ByIndex(int nPlayer);                  /* the player's actor */
extern int   Ov002_FindKeyEntryIndex(int nKey);                         /* key -> entry index */
extern Ov017KeyEntry *Ov002_GetRootField8d14(int nIndex);              /* entry index -> entry */
extern int   Session_IsActive(void);                                     /* Session_IsActive */
extern int   Ov002_RecordElementHit(void *pPiece, void *pMessage, int nKind); /* queue a message on the piece */
extern int   GameState_GetField(int nField, int nBit);                      /* GameState_GetField */
extern void  GameState_SetField(unsigned int nField, unsigned int nBit, unsigned int nValue);          /* GameState_SetField */
extern void  Ov002_SetFieldBit0(void *pPiece, int nMode);            /* retire a piece */
extern void *Ov002_DoneTick(void *pPiece);                       /* terminal state */

void *Ov017_ItemGivenStep(Ov017Item *pSelf)
{
    Ov017ItemMessage msgGive;
    Ov017ItemMessage msgDone;
    Ov017PlayerActor *pActor;
    Ov017KeyEntry *pEntry;
    int nDelta;
    int nState;
    u8 nSpawn;
    int nFlags;
    int nKey;

    nDelta = Ov002_GetModuleScale();
    pSelf->nTimer += nDelta;
    if (pSelf->nState == 5 && pSelf->nTimer >= 0xc000) {
        pSelf->nState = 6;
        if (Session_GetLocalPlayerIndex() == 0 && Ov002_IsSessionOpen() != 0) {
            pActor = GetEntryField20ByIndex(pSelf->nPlayer);
            pEntry = Ov002_GetRootField8d14((short)(Ov002_FindKeyEntryIndex((short)pSelf->nItemKey)));
            if (Session_IsActive() != 0) {
                msgGive.nType = 3;
                Ov002_RecordElementHit(pSelf, &msgGive, 4);
            } else {
                nFlags = pEntry->nFlags & 0xff;
                nKey = pEntry->nKey;
                nSpawn = pSelf->nSpawnId;
                if (pActor->pSub->pfnGiveItem != 0) {
                    pActor->pSub->pfnGiveItem(pActor->pSub, nSpawn, nFlags, nKey);
                }
            }
        }
    }
    if (pSelf->nTimer + nDelta >= 0x1d000) {
        nState = GameState_GetField((u16)pSelf->nStateField, (u8)pSelf->nStateBit);
        GameState_SetField((u16)pSelf->nStateField, (u8)pSelf->nStateBit,
                           (u16)((nState & 0xffff0001) | 2));
        GameState_SetField((u16)pSelf->nTakenField, (u8)pSelf->nTakenBit, (u16)1);
        Ov002_SetFieldBit0(pSelf, 0);
        pSelf->nState = 7;
        if (Session_GetLocalPlayerIndex() == 0) {
            msgDone.nType = 4;
            Ov002_RecordElementHit(pSelf, &msgDone, 4);
        }
        return Ov002_DoneTick;
    }
    return 0;
}
