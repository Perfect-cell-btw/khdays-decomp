
#include "nitro/types.h"

extern int ScriptVm_ReadOperandInt(void *pCtx, int nOperand);
extern int ScriptVm_ReadOperandFx32(void *pCtx, int nOperand);
extern int func_02020400(int a, int b);
extern int Ov002_GetModuleSlot(int nId);
extern void Ov002_CreatePlacedPiece(int nOwner, u16 wA, int wB, void *pPos, short nAngle,
                                    short nExtra, u16 wLow, int bHigh);

/* Script VM command: spawn an element from the command's operands.
 *
 * The three fixed point operands at +0x20, +0x28 and +0x30 form the position
 * and are handed on as a block; the rest are read as plain integers. The word
 * baked into the command at +0x1c is not an operand at all - it is read
 * straight out of the command and split into a halfword and a byte. The raw
 * angle operand is turned into a fixed point rotation by the 0x168 divisor.
 *
 * Always returns 1, which is this VM's "command handled".
 */
int Ov002_ScriptCmdSpawnElement(void *pCtx, int nArgs)
{
    int aPos[3];
    unsigned int nPacked;
    int nRawAngle;
    u16 wAngle;
    int nExtra;
    int nId;
    int nOwner;
    int nA;
    int nB;

    aPos[0] = ScriptVm_ReadOperandFx32(pCtx, nArgs + 0x20);
    aPos[1] = ScriptVm_ReadOperandFx32(pCtx, nArgs + 0x28);
    aPos[2] = ScriptVm_ReadOperandFx32(pCtx, nArgs + 0x30);

    nPacked = *(unsigned int *)((char *)nArgs + 0x1c);
    nRawAngle = ScriptVm_ReadOperandInt(pCtx, nArgs + 0x38);
    wAngle = (u16)func_02020400(nRawAngle << 0x10, 0x168);
    nExtra = ScriptVm_ReadOperandInt(pCtx, nArgs + 0x40);

    nId = ScriptVm_ReadOperandInt(pCtx, nArgs);
    nOwner = Ov002_GetModuleSlot(nId);

    nA = ScriptVm_ReadOperandInt(pCtx, nArgs + 0x08);
    nB = ScriptVm_ReadOperandInt(pCtx, nArgs + 0x10);

    Ov002_CreatePlacedPiece(nOwner, (u16)nA, (u16)nB, &aPos[0], (short)wAngle, (short)nExtra,
                            (u16)nPacked, (unsigned char)(u16)(nPacked >> 0x10));
    return 1;
}
