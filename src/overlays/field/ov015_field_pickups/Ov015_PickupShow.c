/* Ov015_PickupShow -- Ov015_PickupShow: the pickup's show handler.  With a model
 * (+0x2c) it is submitted to the renderer under the kind's table byte (ov002 0207285c)
 * and its binding byte 1 set to 5.  The collidable flag (bit 3 of +0x12) is then decided:
 * off once the pickup was collected (bit 1 of +0x14d) or, for a pickup that reveals a
 * linked object (bit 7 clear), unless the first link key (+0x14e) resolves to a record
 * (ov002 02074460) -- then the linked object's node is hidden (ov002 02073ed0, show 0,
 * priority -1) and the pickup stays collidable.
 * Finally the model's sequence is started at the kind's spin speed (kind row 020828d4 by the
 * class's kind byte +0x84, << 12) with the pickup's rise speed (+0x138). */
#include "nitro/types.h"

typedef struct Ov015PickupKindRow {
    void *pHandlers;          /* 0x00: state function of the kind */
    u8   nRise;               /* 0x04: rise speed scale (random range) */
    u8   pad_05[3];
} Ov015PickupKindRow;

extern int  Ov002_GetCtxTableByte(int nKind);                          /* kind -> table byte */
extern void Render_SubmitNode(void *pNode, u16 nId, int nArg, void *pParams); /* Render_SubmitNode */
extern void Actor_SetBindingByte(void *pBinding, int nIndex, u8 nValue);   /* Actor_SetBindingByte */
extern int  Ov002_FindKeyIndex(int nKey);                           /* record index of a keyed object */
extern void Ov002_SetKeyNodeVisible(int nKey, int bShow, int nPriority); /* show / hide a keyed object's node */
extern void Ov015_StoreArgsRunTwoSubActionsIfFlag4(void *pPickup, void *pSequence, int nArg, int nSpin, int nRise); /* Ov015_StoreArgsRunTwoSubActionsIfFlag4 */
extern const Ov015PickupKindRow data_ov015_020828d4[];             /* per-kind pickup rows */

typedef struct Ov015PickupDef {
    u8   pad_00[0x84];
    u8   nKind;               /* 0x84 */
} Ov015PickupDef;

typedef struct Ov015Pickup {
    u8   pad_000[8];
    Ov015PickupDef *pDef;     /* 0x008 */
    u8   pad_00c[4];
    u8   nKind;               /* 0x010 */
    u8   pad_011;
    u16  nFlags;              /* 0x012: bit 3 collidable */
    u8   pad_014[0x2c - 0x14];
    u8  *pModel;              /* 0x02c */
    u8   pad_030[0x138 - 0x30];
    int  nRiseSpeed;          /* 0x138 */
    u8   pad_13c[0x14d - 0x13c];
    u8   nStateBits;          /* 0x14d: bit 1 collected, bit 7 no linked object */
    short aLinkKey[2];        /* 0x14e: keys of the objects revealed on collection */
} Ov015Pickup;

void Ov015_PickupShow(Ov015Pickup *pPickup)
{
    Ov015PickupDef *pDef;
    int bCollidable;

    bCollidable = 1;
    pDef = pPickup->pDef;
    if (pPickup->pModel != 0) {
        Render_SubmitNode(pPickup->pModel, Ov002_GetCtxTableByte(pPickup->nKind), 0, 0);
        Actor_SetBindingByte(pPickup->pModel + 0x11c, 1, 5);
    }
    if (pPickup->nStateBits & 2) {
        bCollidable = 0;
    } else if ((pPickup->nStateBits & 0x80) == 0) {
        bCollidable = 0;
        if (pPickup->aLinkKey[0] >= 0 && Ov002_FindKeyIndex(pPickup->aLinkKey[0]) >= 0) {
            Ov002_SetKeyNodeVisible(pPickup->aLinkKey[0], 0, -1);
            bCollidable = 1;
        }
    }
    if (bCollidable) {
        pPickup->nFlags |= 8;
    } else {
        pPickup->nFlags &= ~8;
    }
    if (pPickup->pModel != 0) {
        Ov015_StoreArgsRunTwoSubActionsIfFlag4(pPickup, pPickup->pModel + 0x10, 0, data_ov015_020828d4[pDef->nKind].nRise << 12, pPickup->nRiseSpeed);
    }
}
