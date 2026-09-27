/* func_ov023_02086538 -- Ov023_CmdWarpActor: script command that moves an actor to a position
 * at once.  Operand 0 is the entity (0202bfcc) and, resolved (02020d10), the actor; an actor
 * with a model resource (+0x15e0) is first detached (02088f90) and reset (02089174).  Operands
 * 3..5 give the position.  Without operand 2 it is applied (0202b450) with the facing of
 * operand 6 in degrees; as "AnchorPos<n>" the position is rotated by the anchor's angle (event
 * block +0x474, FX_SinCosTable_) and offset by its position (+0x444) and the anchor's angle is
 * the facing; any other name is a spot of the actor's group (0202bfa0, 0202b0b8) whose
 * position is added, its angle (0202b150) being the facing.  The facing goes to the model
 * (02088e78) when there is one, else onto the entity (+0x80, flag bit 5 of +4) unless its
 * bit 5 at +0 is set.  The entity is then shown (0202beb8 1).  Returns 1. */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;

typedef struct VecFx32 {
    int  x;                   /* 0x00 */
    int  y;                   /* 0x04 */
    int  z;                   /* 0x08 */
} VecFx32;

typedef struct Ov023Operand {
    s16  nType;               /* 0x00 */
    u8   pad_02[6];
} Ov023Operand;               /* 0x08 */

typedef struct Ov023Actor {
    u8   pad_0000[0x15e0];
    void *pResource;          /* 0x15e0 */
    u8   pad_15e4[0x1a64 - 0x15e4];
} Ov023Actor;

typedef struct Ov023EventBlock {
    u8   pad_000[0x440];
    Ov023Actor *pActors;      /* 0x440 */
    VecFx32 aAnchorPos[4];    /* 0x444 */
    int  aAnchorAngle[4];     /* 0x474 */
} Ov023EventBlock;

typedef struct Ov023ScriptCtx {
    u8   pad_000[0x128];
    Ov023EventBlock *pEvent;  /* 0x128 */
} Ov023ScriptCtx;

typedef struct Ov023Entity {
    int  nFlags;              /* 0x00 */
    u16  wFlags;              /* 0x04 */
    u8   pad_06[0x80 - 0x06];
    u16  nAngle;              /* 0x80 */
} Ov023Entity;

extern int   func_02021980(Ov023ScriptCtx *pCtx, Ov023Operand *pOperand);   /* ScriptVm_ReadOperandInt */
extern int   func_02021994(Ov023ScriptCtx *pCtx, Ov023Operand *pOperand);   /* ScriptVm_ReadOperandFx32 */
extern char *func_02021948(Ov023ScriptCtx *pCtx, Ov023Operand *pOperand);   /* ScriptVm_ReadOperandString */
extern int   func_02020d10(Ov023ScriptCtx *pCtx, int nIndex);      /* resolve an actor index */
extern Ov023Entity *func_0202bfcc(u16 nEntity);                     /* Entity_Get */
/* The quotient is the low half of the helper's long long return; writing `/` emits _s32_div_f,
 * which is not linkable here. */
extern long long func_02020400(int nNumerator, int nDenominator);
extern void  func_0202b450(Ov023Entity *pEntity, VecFx32 *pPos);   /* Entity_SetPositionNow */
extern void  func_0202beb8(u16 nEntity, int bVisible);              /* Entity_SetVisible */
extern int   strncmp(const char *pA, const char *pB, int nCount);
extern int   func_020200b4(char *pszNumber);                        /* parse a number */
extern int   func_02005418(int nA, int nB);                         /* FX_Mul */
extern void *func_0202bfa0(u16 nGroup);                             /* the actor group by id */
extern int   func_0202b0b8(void *pGroup, char *pszSpot, VecFx32 *pOut); /* Group_GetSpotPosition */
extern int   func_0202b150(void *pGroup, char *pszSpot);            /* Group_GetSpotAngle */
extern void  VEC_Add(const VecFx32 *pA, const VecFx32 *pB, VecFx32 *pOut);
extern void  func_ov023_02088f90(Ov023Actor *pActor);               /* Ov023_DetachActorModel */
extern void  func_ov023_02089174(Ov023Actor *pActor);               /* Ov023_ResetActorModel */
extern void  func_ov023_02088e78(Ov023Actor *pActor, int nAngle);   /* Ov023_SetActorAngle */
extern const short data_0203d210[];                                 /* FX_SinCosTable_: sin, cos pairs */
extern char  data_ov023_0208a5cc[];                                 /* "AnchorPos" */

/* Give an entity a heading unless it is locked (bit 5 of its flags). */
static inline void Ov023_EntitySetAngle(Ov023Entity *pEntity, int nAngle)
{
    if (!(pEntity->nFlags & 0x20)) {
        pEntity->nAngle = nAngle;
        pEntity->wFlags |= 0x20;
    }
}

int func_ov023_02086538(Ov023ScriptCtx *pCtx, Ov023Operand *pOperand)
{
    VecFx32 vPos;
    VecFx32 vSpot;
    int nAngle;
    int nActor;
    Ov023Entity *pEntity;
    char *pszName;
    int nAnchor;
    int nX;
    s16 nSin;
    int nCos;
    int nZ;
    int nIdx;


    nActor = func_02021980(pCtx, pOperand);
    pEntity = func_0202bfcc((u16)nActor);
    nActor = func_02020d10(pCtx, nActor);
    if (pCtx->pEvent->pActors != 0) {
        if (pCtx->pEvent->pActors[nActor].pResource != 0) {
            func_ov023_02088f90(&pCtx->pEvent->pActors[nActor]);
            func_ov023_02089174(&pCtx->pEvent->pActors[nActor]);
        }
    }
    vPos.x = func_02021994(pCtx, pOperand + 3);
    vPos.y = func_02021994(pCtx, pOperand + 4);
    vPos.z = func_02021994(pCtx, pOperand + 5);
    if (pOperand[2].nType == 0) {
        u16 nFacing;

        nFacing = (u16)func_02020400(func_02021980(pCtx, pOperand + 6) << 16, 360);
        func_0202b450(pEntity, &vPos);
        if (pCtx->pEvent->pActors != 0 && pCtx->pEvent->pActors[nActor].pResource != 0) {
            func_ov023_02088e78(&pCtx->pEvent->pActors[nActor], nFacing);
        } else {
            Ov023_EntitySetAngle(pEntity, nFacing);
        }
    } else {
        pszName = func_02021948(pCtx, pOperand + 2);
        if (strncmp(pszName, data_ov023_0208a5cc, 9) == 0) {
            pszName += 9;
            nAnchor = func_020200b4(pszName);
            nIdx = (pCtx->pEvent->aAnchorAngle[nAnchor] >> 4) * 2;
            nSin = data_0203d210[nIdx];
            nCos = data_0203d210[nIdx + 1];
            nCos = (s16)nCos;
            nX = pCtx->pEvent->aAnchorPos[nAnchor].x + func_02005418(nCos, vPos.x) + func_02005418(nSin, vPos.z);
            /* A no-op re-assignment of the short sine between its two uses: it keeps the
             * s16 variable itself (not an int promotion temporary) in the register, which is
             * what orders its spill store right after the muls in the original. */
            nSin = (s16)nSin;
            nZ = pCtx->pEvent->aAnchorPos[nAnchor].z + func_02005418(-nSin, vPos.x) + func_02005418(nCos, vPos.z);
            vPos.x = nX;
            vPos.z = nZ;
            vPos.y = vPos.y + pCtx->pEvent->aAnchorPos[nAnchor].y;
            func_0202b450(pEntity, &vPos);
            if (pCtx->pEvent->pActors != 0 && pCtx->pEvent->pActors[nActor].pResource != 0) {
                func_ov023_02088e78(&pCtx->pEvent->pActors[nActor], pCtx->pEvent->aAnchorAngle[nAnchor]);
            } else {
                Ov023_EntitySetAngle(pEntity, pCtx->pEvent->aAnchorAngle[nAnchor]);
            }
        } else {
            if (func_0202b0b8(func_0202bfa0((u16)nActor), pszName, &vSpot) != 0) {
                VEC_Add(&vSpot, &vPos, &vSpot);
                func_0202b450(pEntity, &vSpot);
                nAngle = func_0202b150(func_0202bfa0((u16)nActor), pszName);
            } else {
                func_0202b450(pEntity, &vPos);
            }
            if (pCtx->pEvent->pActors != 0 && pCtx->pEvent->pActors[nActor].pResource != 0) {
                func_ov023_02088e78(&pCtx->pEvent->pActors[nActor], nAngle);
            } else {
                Ov023_EntitySetAngle(pEntity, nAngle);
            }
        }
    }
    func_0202beb8((u16)nActor, 1);
    return 1;
}
