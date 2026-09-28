typedef unsigned short u16;

extern int ScriptVm_ReadOperandInt(void *pCtx, int nOperand);
extern int ScriptVm_ReadOperandFx32(void *pCtx, int nOperand);
extern int func_02020400(int a, int b);
extern int Ov002_GetModuleSlot(int nId);
extern void Ov002_SpawnPieceElement(int nOwner, u16 wA, u16 wB, u16 wStateField,
                                int bStateWidth, void *pPos, int nAngle);

/* Script VM command: spawn a placed piece from the command's operands.
 *
 * The spawner this calls places a piece's node with its class's placement
 * parameters; the line element has its own command and its own spawner. Same
 * family otherwise: the word baked into the command at +0x1c is read before
 * anything else here and splits into the state field and its width, the three
 * fixed point operands form the position, and the raw angle is divided by 0x168
 * and kept signed.
 *
 * Always returns 1.
 */
int Ov002_ScriptCmdSpawnPlacedPiece(void *pCtx, int nArgs)
{
    int aPos[3];
    unsigned int nPacked;
    int nId;
    int nA;
    int nB;
    int nAngle;
    int nOwner;

    nPacked = *(unsigned int *)((char *)nArgs + 0x1c);

    nId = ScriptVm_ReadOperandInt(pCtx, nArgs);
    nA = ScriptVm_ReadOperandInt(pCtx, nArgs + 0x08);
    nB = ScriptVm_ReadOperandInt(pCtx, nArgs + 0x10);

    aPos[0] = ScriptVm_ReadOperandFx32(pCtx, nArgs + 0x20);
    aPos[1] = ScriptVm_ReadOperandFx32(pCtx, nArgs + 0x28);
    aPos[2] = ScriptVm_ReadOperandFx32(pCtx, nArgs + 0x30);

    nAngle = (short)func_02020400(ScriptVm_ReadOperandInt(pCtx, nArgs + 0x38) << 0x10,
                                  0x168);

    nOwner = Ov002_GetModuleSlot(nId);

    Ov002_SpawnPieceElement(nOwner, (u16)nA, (u16)nB, (u16)nPacked,
                        (unsigned char)(u16)(nPacked >> 0x10), &aPos[0],
                        nAngle);
    return 1;
}
