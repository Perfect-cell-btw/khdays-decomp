/* Activate a spot from a local or replicated six-byte command.
 * The permission callback gates requests; confirmed commands bind the action
 * owner, reset spin, choose direction and invoke the activation callback.
 * The third router payload is intentionally unused. ARM, 444 bytes.
 */

#include "nitro/types.h"

typedef struct Ov002SpotActionOwner Ov002SpotActionOwner;
typedef struct Ov022SeatEntry {
    char pad000[8];
    u8 bSeat;
    char pad009[0x5d];
    s16 nSlotId;
    char pad068[0x484];
    Ov002SpotActionOwner *pOwner;
} Ov022SeatEntry;

struct Ov002SpotActionOwner {
    char pad000[0x1bc];
    void (*pfnActivate)(Ov002SpotActionOwner *, int, int, u16);
    int (*pfnCanActivate)(Ov002SpotActionOwner *, int, int, u16);
};

typedef struct Ov002Spawned {
    char pad000[0x28];
    Ov002SpotActionOwner *pActionOwner;
    u8 nKind;
    u8 nSpotId;
    u16 nTier;
    u8 bFlag0 : 1;
    u8 bActivationPending : 1;
    u8 bOtherFlags : 6;
    s8 nSpinDirection;
    u8 nCtxIndex;
    char pad033;
    s16 nSpin;
} Ov002Spawned;

typedef struct Ov002Rng { int nSeed, nMult, nInc; } Ov002Rng;
typedef struct Ov002SpotStage {
    char pad000[0x4e];
    u16 nRowStride;
    char pad050[4];
    char *pRows;
    char pad058[0x24c0];
    Ov002Rng rng;
} Ov002SpotStage;
typedef struct Ov002SpotHolder {
    char pad000[4];
    Ov002SpotStage *pStage;
} Ov002SpotHolder;
typedef struct Ov002SpotCmd {
    u8 bMode, bKind;
    u16 wSpot;
    u8 bPacked, bPad;
} Ov002SpotCmd;

extern Ov002SpotHolder data_ov002_0207fa28;
extern int Ov002_IsSessionOpen(void);
extern Ov022SeatEntry *GetEntryField20ByIndex(int nSeat);
extern int Session_IsReady(void);
extern int Session_IsActive(void);
extern int Session_GetLocalPlayerIndex(void);
extern int Ov002_PostSpotCommand(Ov002Spawned *, int, u8, int);
extern void Ov002_PlaySlotActionSound(Ov002SpotActionOwner *, int);
extern int Ov002_GetSlotTableByte(int);
extern void Ov002_ReleaseSlotOwner(Ov002Spawned *);

static inline int CanActivate(Ov002SpotActionOwner *pOwner, int nSpot, int nKind, u16 nTier)
{
    if (pOwner->pfnCanActivate == 0) return 1;
    return pOwner->pfnCanActivate(pOwner, nSpot, nKind, nTier);
}
static inline void Activate(Ov002SpotActionOwner *pOwner, int nSpot, int nKind, u16 nTier)
{
    if (pOwner->pfnActivate != 0) pOwner->pfnActivate(pOwner, nSpot, nKind, nTier);
}
static inline u16 RandRange(Ov002Rng *pRng, u16 nLimit)
{
    pRng->nSeed = pRng->nMult * pRng->nSeed + pRng->nInc;
    return (u16)((((u32)pRng->nSeed >> 16) * nLimit) >> 16);
}

void Ov002_ActivateSpotFromCommand(int nSpotId, Ov002SpotCmd *pCmd, void *pPayload)
{
    Ov002Spawned *pRow;
    int nPackHigh;
    u8 nPackLow;
    Ov022SeatEntry *pSeat;
    Ov002SpotActionOwner *pOwner;

    pRow = (Ov002Spawned *)(data_ov002_0207fa28.pStage->pRows +
        data_ov002_0207fa28.pStage->nRowStride * nSpotId);
    nPackHigh = (u8)(pCmd->bPacked >> 5);
    nPackLow = pCmd->bPacked & 0x1f;
    if (!Ov002_IsSessionOpen()) return;
    pSeat = GetEntryField20ByIndex(nPackHigh);
    pOwner = pSeat->pOwner;
    if (pCmd->bMode == 0) {
        if (!Session_IsReady()) return;
        if (pRow->bActivationPending || pRow->pActionOwner != 0) return;
        if (!CanActivate(pOwner, pRow->nSpotId, pRow->nKind, pRow->nTier)) return;
        pRow->bActivationPending = 1;
        if (Session_IsActive()) {
            Ov002_PostSpotCommand(pRow, nPackHigh, nPackLow, 1);
            return;
        }
    }
    if (pRow->pActionOwner != 0) return;
    pRow->bActivationPending = 1;
    pRow->pActionOwner = pOwner;
    pRow->nSpin = 0;
    pRow->nSpinDirection = Session_IsActive() ? 1 :
        (RandRange(&data_ov002_0207fa28.pStage->rng, 2) ? -1 : 1);
    if (Session_GetLocalPlayerIndex() == 0 || pSeat->bSeat == Session_GetLocalPlayerIndex()) {
        Activate(pOwner, pRow->nSpotId, pRow->nKind, pRow->nTier);
    }
    Ov002_PlaySlotActionSound(pOwner, pRow->nKind);
    if (pRow->nCtxIndex != Ov002_GetSlotTableByte(pSeat->nSlotId)) Ov002_ReleaseSlotOwner(pRow);
}
