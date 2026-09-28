#include "nitro/types.h"

extern int ScriptVm_ReadOperandInt(void *pCtx, int nArgs);
extern int ScriptVm_ReadOperandFx32(void *pCtx, int nArgs);
extern char *ByteCode_ResolveOperand(void *pCtx, int nArgs);
extern int func_02020400(int a, int b);
extern int Ov002_WriteSessionMarker(int nWho, int nWhat, int *pPos, int nAngle,
                               char *pName, int nFlags);
extern void Ov002_SetRosterSlotTargets(int *pPos, int nAngle);

/* Script VM command: move one roster slot somewhere.
 *
 * Operand slots are eight bytes each and the leading halfword is the kind tag.
 * A zero third tag means the command carries the destination itself -- three
 * fixed point coordinates and a heading in degrees, turned into a rotation
 * through the same 0x168 divisor the other move commands use.  Otherwise the
 * operand names the destination instead.
 *
 * If the move is accepted the camera aim is cleared and the command reports 1;
 * a rejected move reports 0.
 *
 * The heading is only written on the branch that carries one, and the named
 * branch hands on whatever it happened to hold -- that is what the game does.
 */
int Ov002_ScriptMoveSlot(void *pCtx, int nArgs)
{
    int nWho;
    int nWhat;
    int aPos[3];
    char *pName;
    int nAngle;

    pName = 0;
    nWho = ScriptVm_ReadOperandInt(pCtx, nArgs);
    nWhat = ScriptVm_ReadOperandInt(pCtx, nArgs + 8);

    if (*(short *)((char *)nArgs + 0x10) == 0) {
        aPos[0] = ScriptVm_ReadOperandFx32(pCtx, nArgs + 0x18);
        aPos[1] = ScriptVm_ReadOperandFx32(pCtx, nArgs + 0x20);
        aPos[2] = ScriptVm_ReadOperandFx32(pCtx, nArgs + 0x28);
        nArgs += 0x30;
        nAngle = (u16)func_02020400(ScriptVm_ReadOperandInt(pCtx, nArgs) << 0x10,
                                    0x168);
    } else {
        nArgs += 0x10;
        pName = ByteCode_ResolveOperand(pCtx, nArgs);
    }

    if (Ov002_WriteSessionMarker(nWho, nWhat, aPos, nAngle, pName, 0) != 0) {
        Ov002_SetRosterSlotTargets(0, -1);
        return 1;
    }
    return 0;
}
