/* Ov015_PickupTakenStep -- Ov015_PickupTakenStep: the taken flow of a model-less pickup.
 * State 2 collects it (0207fcec); an invisible pickup (bit 2 of +0x12 clear) is finished at
 * once, a visible one rewinds its sequence (ov002 0207c618 track 0 frame 0), disables the
 * node (0202af2c), marks the taken sequence playing (bit 0 of +0x14d) and moves to state 3.
 * State 3 waits for the taken sequence (0207fdc4, again finished at once when invisible).
 * Finishing clears the playing bit, enters state 4, marks the GameState field collected
 * (bit 1, keeping bit 0), retires the piece (ov002 02076bd8 mode 0) and hands back the
 * vanish step (ov002 0207cea4); otherwise 0 is returned.
 * Codegen: the done flag is zeroed after the delta call and the case-3 result is folded
 * through an if (not `!= 0`); both are needed for the parameter to stay in r5. */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int  Ov002_GetModuleScale(void);                              /* frame delta */
extern int  Ov015_PickupCollect(void *pPickup);                     /* Ov015_PickupCollect */
extern void Ov002_RebindAnimTracks(u16 *pNode, int nTrack, int nFrame); /* rewind a sequence */
extern void SceneNode_Disable(u16 *pNode);                              /* SceneNode_Disable */
extern int  Ov015_PickupPlayTakenSequence(void *pPickup, int nDelta);         /* Ov015_PickupPlayTakenSequence */
extern int  GameState_GetField(u16 nField, u8 nBit);                     /* GameState_GetField */
extern void GameState_SetField(u16 nField, u8 nBit, u16 nValue);         /* GameState_SetField */
extern void Ov002_SetFieldBit0(void *pPiece, int nMode);           /* retire the piece */
typedef void *Ov015StateFn(void *pPiece);
extern Ov015StateFn Ov002_DoneTick;                            /* the vanish step */

typedef struct Ov015Pickup {
    u8   pad_000[0x12];
    u16  nFlags;              /* 0x012: bit 2 visible */
    u16  nStateField;         /* 0x014 */
    u8   nStateBit;           /* 0x016 */
    u8   pad_017[0x30 - 0x17];
    u16  sequence;            /* 0x030 */
    u8   pad_032[0x14c - 0x32];
    u8   nState;              /* 0x14c */
    u8   nStateBits;          /* 0x14d */
} Ov015Pickup;

Ov015StateFn *Ov015_PickupTakenStep(Ov015Pickup *pPickup)
{
    int nDelta;
    int bDone;
    u32 nField;

    nDelta = Ov002_GetModuleScale();
    bDone = 0;
    switch (pPickup->nState) {
    case 2:
        Ov015_PickupCollect(pPickup);
        if ((pPickup->nFlags & 4) == 0) {
            bDone = 1;
        } else {
            Ov002_RebindAnimTracks(&pPickup->sequence, 0, 0);
            SceneNode_Disable(&pPickup->sequence);
            pPickup->nStateBits |= 1;
            pPickup->nState = 3;
        }
        break;
    case 3:
        if (pPickup->nFlags & 4) {
            if (Ov015_PickupPlayTakenSequence(pPickup, nDelta)) {
                bDone = 1;
            }
        } else {
            bDone = 1;
        }
        break;
    }
    if (bDone) {
        pPickup->nStateBits &= ~1;
        pPickup->nState = 4;
        nField = GameState_GetField(pPickup->nStateField, pPickup->nStateBit);
        GameState_SetField(pPickup->nStateField, pPickup->nStateBit, (nField & 0xffff0001) | 2);
        Ov002_SetFieldBit0(pPickup, 0);
        return Ov002_DoneTick;
    }
    return 0;
}
