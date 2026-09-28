/* Ov015_SpotFacingForInteraction -- Ov015_SpotFacingForInteraction: the spot's facing word (+0x28)
 * while the spot is live (bit 1 of +0x40) and the local player's actor is in interaction
 * state 0xc; 0 otherwise.  Sibling of Ov015_GetTargetIfInRange, which hands out the spot's
 * position (+0x1c) under the same test. */
typedef unsigned char u8;

extern int QueryActiveStateOrDelegate(void);                         /* the local peer */
extern void *GetEntryField20ByIndex(int nPlayer);                /* the player's actor */
extern int Ov022_ForwardArg1(void *pActor, int nState); /* the actor is in interaction state nState */

typedef struct Ov015Spot {
    u8  pad_00[0x1c];
    int aPosition[3];         /* 0x1c */
    int nFacing;              /* 0x28 */
    u8  pad_2c[0x40 - 0x2c];
    u8  nFlags;               /* 0x40: bit 1 = the spot is live */
} Ov015Spot;

int Ov015_SpotFacingForInteraction(Ov015Spot *pSpot)
{
    if (pSpot->nFlags & 2) {
        if (Ov022_ForwardArg1(GetEntryField20ByIndex(QueryActiveStateOrDelegate()), 0xc)) {
            return pSpot->nFacing;
        }
    }
    return 0;
}
