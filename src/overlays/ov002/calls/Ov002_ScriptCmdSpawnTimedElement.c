typedef unsigned short u16;

extern int ScriptVm_ReadOperandInt(void *pCtx, int nOperand);
extern int ScriptVm_ReadOperandFx32(void *pCtx, int nOperand);
extern int func_02020400(int a, int b);
extern int Ov002_GetModuleSlot(int nId);
extern void Ov002_SpawnTimedElement(int nOwner, u16 wA, u16 wB, u16 wLow,
                                int bHigh, void *pPos, short nAngle);

/* Script VM command: start a timed element from the command's operands.
 *
 * Same shape as the other spawn commands in this overlay: the plain integers
 * come out first, the word baked into the command at +0x1c splits into a
 * halfword and a byte, the three fixed point operands form the position, and
 * the raw angle is turned into a fixed point rotation by the 0x168 divisor.
 *
 * Always returns 1.
 */
int Ov002_ScriptCmdSpawnTimedElement(void *pCtx, int nArgs)
{
    int aPos[3];
    int nId;
    int nA;
    int nB;
    unsigned int nPacked;
    int nRawAngle;
    u16 wAngle;
    int nOwner;

    nId = ScriptVm_ReadOperandInt(pCtx, nArgs);
    nA = ScriptVm_ReadOperandInt(pCtx, nArgs + 0x08);
    nB = ScriptVm_ReadOperandInt(pCtx, nArgs + 0x10);

    nPacked = *(unsigned int *)((char *)nArgs + 0x1c);

    aPos[0] = ScriptVm_ReadOperandFx32(pCtx, nArgs + 0x20);
    aPos[1] = ScriptVm_ReadOperandFx32(pCtx, nArgs + 0x28);
    aPos[2] = ScriptVm_ReadOperandFx32(pCtx, nArgs + 0x30);

    nRawAngle = ScriptVm_ReadOperandInt(pCtx, nArgs + 0x38);
    wAngle = (u16)func_02020400(nRawAngle << 0x10, 0x168);

    nOwner = Ov002_GetModuleSlot(nId);

    Ov002_SpawnTimedElement(nOwner, (u16)nA, (u16)nB, (u16)nPacked,
                        (unsigned char)(u16)(nPacked >> 0x10), &aPos[0],
                        (short)wAngle);
    return 1;
}
