
#include "nitro/types.h"

extern int ScriptVm_ReadOperandInt(void *pCtx, int nOperand);
extern int ScriptVm_ReadOperandFx32(void *pCtx, int nOperand);
extern int ByteCode_ResolveOperand(void *pCtx, int nOperand);
extern int Ov002_GetModuleSlot(int nId);
/* The narrow arguments are declared int here, not u16 or signed char: every one
 * of them is already narrowed where it is unpacked or read, and a narrow
 * parameter would make the compiler narrow it a second time at the call. */
extern void Ov002_SpawnSpareEntry(int nOwner, int wA, int wB, void *pPos, int nStateField,
                                  int nStateWidth, int nQueuedWidth, int nCount, int nName,
                                  int nLine, int nParamA, int nParamB, int bArm, int bWide);

/* Script VM command: spawn a spare entry from the command's operands.
 *
 * The widest command of the family. Two text operands are optional and the
 * command block carries a tag beside each saying whether it is there at all;
 * two more operands are read as signed bytes; two are read only for their
 * truth. The word baked into the command at +0x1c splits into the state field
 * and its width, and the three fixed point operands at the end form the
 * position.
 *
 * Always returns 1.
 */
int Ov002_ScriptCmdSpawnSpareEntry(void *pCtx, int nArgs)
{
    int aPos[3];
    int nQueuedWidth;
    int nCount;
    int nStateField;
    int nStateWidth;
    int nId;
    int nA;
    int nB;
    int nParamA;
    int nParamB;
    int nName;
    int nLine;
    unsigned int nPacked;
    int bArm;
    int bWide;
    int nOwner;

    nId = ScriptVm_ReadOperandInt(pCtx, nArgs);
    nA = ScriptVm_ReadOperandInt(pCtx, nArgs + 0x08);
    nB = ScriptVm_ReadOperandInt(pCtx, nArgs + 0x10);

    nPacked = *(unsigned int *)((char *)nArgs + 0x1c);
    nStateField = (u16)nPacked;
    nStateWidth = (unsigned char)(u16)(nPacked >> 0x10);

    nQueuedWidth = (signed char)ScriptVm_ReadOperandInt(pCtx, nArgs + 0x20);
    nCount = (signed char)ScriptVm_ReadOperandInt(pCtx, nArgs + 0x28);

    if (*(short *)((char *)nArgs + 0x30) == 0) {
        nName = 0;
    } else {
        nName = ByteCode_ResolveOperand(pCtx, nArgs + 0x30);
    }

    if (*(short *)((char *)nArgs + 0x38) == 0) {
        nLine = 0;
    } else {
        nLine = ByteCode_ResolveOperand(pCtx, nArgs + 0x38);
    }

    nParamA = ScriptVm_ReadOperandFx32(pCtx, nArgs + 0x40);
    nParamB = ScriptVm_ReadOperandFx32(pCtx, nArgs + 0x48);

    bArm = ScriptVm_ReadOperandInt(pCtx, nArgs + 0x50) != 0;
    bWide = ScriptVm_ReadOperandInt(pCtx, nArgs + 0x58) != 0;

    aPos[0] = ScriptVm_ReadOperandFx32(pCtx, nArgs + 0x60);
    aPos[1] = ScriptVm_ReadOperandFx32(pCtx, nArgs + 0x68);
    aPos[2] = ScriptVm_ReadOperandFx32(pCtx, nArgs + 0x70);

    nOwner = Ov002_GetModuleSlot(nId);

    Ov002_SpawnSpareEntry(nOwner, (u16)nA, (u16)nB, &aPos[0], nStateField, nStateWidth,
                          nQueuedWidth, nCount, nName, nLine, nParamA, nParamB, bArm, bWide);
    return 1;
}
