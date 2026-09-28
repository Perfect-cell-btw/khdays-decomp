
#include "nitro/types.h"

extern int ScriptVm_ReadOperandInt(void *pCtx, int nOperand);
extern int ScriptVm_ReadOperandFx32(void *pCtx, int nOperand);
extern int ByteCode_ResolveOperand(void *pCtx, int nOperand);
extern int func_02020400(int a, int b);
extern int Ov002_GetModuleSlot(int nId);
/* The state field is declared int here, not u16, on purpose: the value is
 * already truncated when it is unpacked, and declaring the parameter narrow
 * would make the compiler truncate it a second time at the call. */
extern void Ov002_SpawnActorElement(int nOwner, u16 wA, u16 wB, int nStateField,
                                int bStateWidth, int nName, int nTrack,
                                int nSpot, void *pPos, void *pBound,
                                int nAngle);

/* Script VM command: spawn an actor element from the command's operands.
 *
 * The widest of this overlay's spawn commands. Two of the operands are
 * polymorphic and the command block carries a type tag beside each: the tag at
 * +0x20 chooses between a handle read (2) and a signed byte track index (1),
 * with neither read leaving the track at -1, and the tag at +0x28 decides
 * whether the spot operand is read at all. The word at +0x1c is baked into the
 * command and splits into the state field and its width; the two vectors are
 * three fixed point operands each; the raw angle is divided by 0x168.
 *
 * Always returns 1.
 */
int Ov002_ScriptCmdSpawnActorElement(void *pCtx, int nArgs)
{
    int aPos[3];
    int aBound[3];
    int nId;
    int nA;
    int nB;
    int nSpot;
    int nName;
    int nAngle;
    int wStateField;
    unsigned int nPacked;
    int nTrack;
    int bStateWidth;
    int nOwner;
    int nTag;

    nSpot = 0;
    nName = 0;
    nTrack = -1;

    nPacked = *(unsigned int *)((char *)nArgs + 0x1c);
    wStateField = (u16)nPacked;
    bStateWidth = (unsigned char)(u16)(nPacked >> 0x10);

    nId = ScriptVm_ReadOperandInt(pCtx, nArgs);
    nA = ScriptVm_ReadOperandInt(pCtx, nArgs + 0x08);
    nB = ScriptVm_ReadOperandInt(pCtx, nArgs + 0x10);

    nTag = *(short *)((char *)nArgs + 0x20);
    if (nTag == 2) {
        nName = ByteCode_ResolveOperand(pCtx, nArgs + 0x20);
    } else if (nTag == 1) {
        nTrack = (signed char)ScriptVm_ReadOperandInt(pCtx, nArgs + 0x20);
    }

    aPos[0] = ScriptVm_ReadOperandFx32(pCtx, nArgs + 0x30);
    aPos[1] = ScriptVm_ReadOperandFx32(pCtx, nArgs + 0x38);
    aPos[2] = ScriptVm_ReadOperandFx32(pCtx, nArgs + 0x40);

    nAngle = (short)func_02020400(ScriptVm_ReadOperandInt(pCtx, nArgs + 0x48) << 0x10,
                                  0x168);

    aBound[0] = ScriptVm_ReadOperandFx32(pCtx, nArgs + 0x50);
    aBound[1] = ScriptVm_ReadOperandFx32(pCtx, nArgs + 0x58);
    aBound[2] = ScriptVm_ReadOperandFx32(pCtx, nArgs + 0x60);

    if (*(short *)((char *)nArgs + 0x28) != 0) {
        nSpot = ByteCode_ResolveOperand(pCtx, nArgs + 0x28);
    }

    nOwner = Ov002_GetModuleSlot(nId);

    Ov002_SpawnActorElement(nOwner, (u16)nA, (u16)nB, wStateField,
                        bStateWidth, nName, nTrack, nSpot, &aPos[0],
                        &aBound[0], nAngle);
    return 1;
}
