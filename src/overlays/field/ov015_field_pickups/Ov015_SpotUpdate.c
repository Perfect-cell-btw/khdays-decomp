/* Ov015_SpotUpdate -- Ov015_SpotUpdate: the spot's per-frame handler.  Without an owner
 * pickup (+0x54), or once the owner's GameState field (+0x14 / +0x16) carries a non-zero
 * count in bits 1..15, the spot is collidable (bit 3 of +0x12).  A pending spot (bit 6 of
 * +0x40) that is armed (bit 0), whose class table names a current entry (+0x179 >= 0) and
 * that has both an occupied callback (+0x4c) and an actor (+0x3c) which has arrived (bit 2
 * of the actor's +0x40) fires the callback with the player's sub-actor (01fffde0 of
 * +0x180, +0x4ec) and the entry id, then drops the pending bit.  Always returns 0. */

#include "nitro/types.h"

extern int GameState_GetField(int nField, int nBit);                    /* GameState_GetField */
extern void *GetEntryField20ByIndex(int nPlayer);                          /* the player's actor */

typedef struct Ov015SpotDef {
    u8  pad_000[0x179];
    s8  nCurrent;             /* 0x179 */
    u8  pad_17a[6];
    s8  nPlayer;              /* 0x180 */
} Ov015SpotDef;

typedef struct Ov015DrivenActor {
    u8  pad_00[0x40];
    int nMoveBits0 : 2;       /* 0x40 */
    int bArrived : 1;         /* 0x40: bit 2 */
} Ov015DrivenActor;

typedef struct Ov015PlayerActor {
    u8  pad_000[0x4ec];
    void *pSub;               /* 0x4ec */
} Ov015PlayerActor;

typedef struct Ov015OwnerPickup {
    u8  pad_00[0x14];
    u16 nStateField;          /* 0x14 */
    u8  nStateBit;            /* 0x16 */
} Ov015OwnerPickup;

typedef struct Ov015Spot {
    u8  pad_00[8];
    Ov015SpotDef *pDef;       /* 0x08 */
    u8  pad_0c[6];
    u16 nFlags;               /* 0x12: bit 3 collidable */
    u8  pad_14[0x3c - 0x14];
    Ov015DrivenActor *pActor; /* 0x3c */
    u8  nSpotFlags;           /* 0x40: bit 0 armed, bit 6 pending */
    u8  pad_41[0xb];
    void (*pfnOccupied)(Ov015DrivenActor *pActor, void *pSub, u8 nEntry); /* 0x4c */
    u8  pad_50[4];
    Ov015OwnerPickup *pOwner; /* 0x54 */
} Ov015Spot;

int Ov015_SpotUpdate(Ov015Spot *pSpot, int nArg1, int nArg2, int nArg3)
{
    Ov015SpotDef *pDef;
    Ov015OwnerPickup *pOwner;

    pOwner = pSpot->pOwner;
    pDef = pSpot->pDef;
    if (pOwner == 0 || (u16)(((unsigned int)GameState_GetField(pOwner->nStateField, pOwner->nStateBit) & 0xfffe) >> 1) != 0) {
        pSpot->nFlags |= 8;
    }
    if ((pSpot->nSpotFlags & 0x40) && (pSpot->nSpotFlags & 1) && pDef->nCurrent >= 0) {
        if (pSpot->pfnOccupied != 0 && pSpot->pActor != 0 && pSpot->pActor->bArrived) {
            pSpot->pfnOccupied(pSpot->pActor, ((Ov015PlayerActor *)GetEntryField20ByIndex(pDef->nPlayer))->pSub, *(u8 *)&pDef->nCurrent);
            pSpot->nSpotFlags &= ~0x40;
        }
    }
    return 0;
}
