
#include "nitro/types.h"

extern int ScriptVm_ReadOperandInt(void *pCtx, int nArgs);
/* Read and write the saved counter 0x20ad, slot 8. */
extern int GameState_GetField(int nId, int nSlot);
extern void GameState_SetField(int nId, int nSlot, u16 nValue);
/* Non-zero while the counter display is already up. */
extern int LoadGlobalPtr4FieldDcOrZero(void);
extern void StoreToGlobalPtr4FieldDcIfSet(int nOn);
extern void Ov002_DispatchHudCounterCommand(int nKind, int nValue, int nFlags);
extern int func_02020400(int nNum, int nDen);
extern void Ov002_SubmitTaskNode(int bWait, int nWhat, int nFlags, int *pOut);

/* Script VM command: award something and show it.
 *
 * Operand slots are eight bytes each: who, what, a kind and an amount.  Kinds
 * 5 and 6 are the running counter -- kind 6 first folds the thousands the save
 * already holds back into the amount -- so the counter is bumped, its display
 * brought up if it was not already, and the new thousands written back to the
 * save.  Any other kind is passed straight through.
 *
 * Always returns 1.
 */
int Ov002_ScriptAwardAndShow(void *pCtx, int nArgs)
{
    int nWho;
    int nWhat;
    int aOut[2];
    int nKind;
    int nAmount;

    nWho = ScriptVm_ReadOperandInt(pCtx, nArgs);
    nWhat = ScriptVm_ReadOperandInt(pCtx, nArgs + 8);
    nKind = ScriptVm_ReadOperandInt(pCtx, nArgs + 0x10);
    nArgs += 0x18;
    nAmount = ScriptVm_ReadOperandInt(pCtx, nArgs);

    if (nKind == 5 || nKind == 6) {
        aOut[0] = 0;
        if (nKind == 6) {
            nAmount += GameState_GetField(0x20ad, 8) * 1000;
        }
        aOut[1] = nAmount;
        Ov002_DispatchHudCounterCommand(2, nAmount, 0);
        if (LoadGlobalPtr4FieldDcOrZero() == 0) {
            StoreToGlobalPtr4FieldDcIfSet(1);
        }
        GameState_SetField(0x20ad, 8, (u16)func_02020400(nAmount, 1000));
    } else {
        aOut[0] = nKind;
        aOut[1] = nAmount;
    }

    Ov002_SubmitTaskNode(nWho == 0, nWhat, 0, aOut);
    return 1;
}
