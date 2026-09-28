/* Ov023_CmdStartLightFade -- Ov023_CmdStartLightFade: script command that starts a fade of one of
 * the light levels (data_ov023_0208a7c0 slots, +0x68; Ov023_GetLightLevel 02089cec /
 * Ov023_SetLightLevel 02089cdc) in the event block's fade fields.  Operand 2 is the light,
 * whose current level becomes the fade's level (+0x20) and start (+0x14); operand 0 is the end
 * (+0x18), operand 1 the frame count (+0x1c) and the elapsed count (+0x24) is cleared.  The
 * command is re-queued (020219b4) for Ov023_CmdStepLightFade (02087018); with no frames the
 * end level is applied at once and 1 returned, else 0. */
#include "nitro/types.h"

typedef struct Ov023EventBlock {
    u8   pad_00[0x14];
    int  nFadeFrom;           /* 0x14 */
    int  nFadeTo;             /* 0x18 */
    int  nFadeFrames;         /* 0x1c */
    int  nFadeLevel;          /* 0x20 */
    int  nFadeElapsed;        /* 0x24 */
} Ov023EventBlock;

typedef struct Ov023ScriptCtx {
    u8   pad_000[0x128];
    Ov023EventBlock *pEvent;  /* 0x128 */
} Ov023ScriptCtx;

extern int  ScriptVm_ReadOperandInt(Ov023ScriptCtx *pCtx, void *pOperand);   /* ScriptVm_ReadOperandInt */
extern int  Ov023_GetGateValue(int nLight);                        /* Ov023_GetLightLevel */
extern void Ov023_SetGateValue(int nLevel, int nLight);            /* Ov023_SetLightLevel */
extern void Slot48_StoreAtCurrentIndex(Ov023ScriptCtx *pCtx, void *pCmd);        /* ScriptVm_RequeueCommand */

int Ov023_CmdStartLightFade(Ov023ScriptCtx *pCtx, u8 *pOperand)
{
    int nLight;

    nLight = ScriptVm_ReadOperandInt(pCtx, pOperand + 0x10);
    pCtx->pEvent->nFadeLevel = Ov023_GetGateValue(nLight);
    pCtx->pEvent->nFadeFrom = pCtx->pEvent->nFadeLevel;
    pCtx->pEvent->nFadeTo = ScriptVm_ReadOperandInt(pCtx, pOperand);
    pCtx->pEvent->nFadeFrames = ScriptVm_ReadOperandInt(pCtx, pOperand + 8);
    pCtx->pEvent->nFadeElapsed = 0;
    Slot48_StoreAtCurrentIndex(pCtx, pOperand);
    if (pCtx->pEvent->nFadeFrames == 0) {
        Ov023_SetGateValue(pCtx->pEvent->nFadeTo, nLight);
        return 1;
    }
    return 0;
}
