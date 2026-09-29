/* Ov017_ItemHit -- Ov017_ItemHit: hit handler of the item piece (a player touching it,
 * the hit record's first byte being the player).  Nothing while a panel is open (ov002
 * 020573cc), a scene change is pending (0206b828) or the shutdown hook says so (0206b7a4);
 * nothing either once the item's taken bit (bit 1 of its GameState field) is set or unless
 * the piece is in state 3 (ready).  Otherwise the item key (+0x1b6) is looked up (ov002
 * 0206d144 / 0206d194) and offered to the player's actor sub-object through its hook at +0x1c0
 * (actor from 01fffde0, sub at +0x4ec; a missing hook counts as accepted): when the hook
 * refuses (0) the item is announced instead (ov022 02088c10 with the player, the entry's key
 * and the spawn id); when it accepts, the piece enters the given state (Ov017_ItemBeginGiven
 * 020804d4), leaves the room (bit 3 of +0x12) and records the player (+0x1b8).  Always 0. */

#include "nitro/types.h"
#include "game/engine.h"

typedef struct Ov017Item {
    u8   pad_000[0x12];
    u16  nPieceFlags;         /* 0x012: bit 3 = in the room */
    u16  nStateField;         /* 0x014: GameState field */
    u8   nStateBit;           /* 0x016 */
    u8   pad_017[0x1b4 - 0x17];
    u8   nState;              /* 0x1b4 */
    u8   pad_1b5;
    short nItemKey;           /* 0x1b6 */
    u8   nPlayer;             /* 0x1b8 */
    char nSpawnId;            /* 0x1b9 */
} Ov017Item;

typedef struct Ov017KeyEntry {
    u8   pad_00[0x40];
    short nKey;               /* 0x40 */
    short nFlags;             /* 0x42 */
} Ov017KeyEntry;

typedef struct Ov017PlayerSub {
    u8   pad_000[0x1c0];
    int (*pfnOfferItem)(struct Ov017PlayerSub *pSub, int nSpawnId, int nFlags, int nKey); /* 0x1c0 */
} Ov017PlayerSub;

typedef struct Ov017PlayerActor {
    u8   pad_000[0x4ec];
    Ov017PlayerSub *pSub;     /* 0x4ec */
} Ov017PlayerActor;

extern int   Ov002_Hud_IsPanelOpen(void);                               /* a panel is open */
extern int   Ov002_GetRootField8b68Alt(void);                               /* a scene change is pending */
extern int   Ov002_RunShutdownHook(void);                               /* the shutdown hook's verdict */
extern int   Ov002_FindKeyEntryIndex(int nKey);                         /* key -> entry index */
extern Ov017KeyEntry *Ov002_GetRootField8d14(int nIndex);              /* entry index -> entry */
extern void  Ov022_Member_ShowSpotMessage(int nPlayer, int nKey, int nSpawnId); /* announce the item */
extern void  Ov017_ResetState5(Ov017Item *pSelf);                   /* Ov017_ItemBeginGiven */

int Ov017_ItemHit(Ov017Item *pSelf, u8 *pHit)
{
    Ov017PlayerActor *pActor;
    Ov017KeyEntry *pEntry;
    u16 nBits;
    int nResult;
    u8 nSpawn;
    int nFlags;
    int nKey;

    nBits = (u16)((GameState_GetField((u16)pSelf->nStateField, (u8)pSelf->nStateBit) & 0xfffe) >> 1);
    if (Ov002_Hud_IsPanelOpen() != 0 || Ov002_GetRootField8b68Alt() != 0 || Ov002_RunShutdownHook() != 0) {
        return 0;
    }
    if ((nBits & 1) == 0 && pSelf->nState == 3) {
        pActor = GetEntryField20ByIndex(pHit[0]);
        pEntry = Ov002_GetRootField8d14((short)(Ov002_FindKeyEntryIndex((short)pSelf->nItemKey)));
        nFlags = pEntry->nFlags & 0xff;
        nKey = (u16)pEntry->nKey;
        nSpawn = pSelf->nSpawnId;
        if (pActor->pSub->pfnOfferItem == 0) {
            nResult = 1;
        } else {
            nResult = pActor->pSub->pfnOfferItem(pActor->pSub, nSpawn, nFlags, nKey);
        }
        if (nResult == 0) {
            Ov022_Member_ShowSpotMessage(pHit[0], pEntry->nKey, pSelf->nSpawnId);
            return 0;
        }
        Ov017_ResetState5(pSelf);
        pSelf->nPieceFlags &= ~8;
        pSelf->nPlayer = pHit[0];
    }
    return 0;
}
