typedef unsigned char u8;

extern int ScriptVm_ReadOperandInt(int pOwner, int pSlot);
extern void Ov002_SubmitTaskNode(int bReady, int nFirst, int nKind, void *pArgs);

/* The kind 4 node's argument block: the first two operands narrow to bytes and
 * the last two go through as words. */
typedef struct Ov002TaskArgsKind4 {
    u8 bFirst;                      /* +0x00 */
    u8 bSecond;                     /* +0x01 */
    char pad0002[2];
    int nThird;                     /* +0x04 */
    int nFourth;                    /* +0x08 */
} Ov002TaskArgsKind4;

/* Resolve the six slots of a request block and submit them as a kind 4 task
 * node: the first slot only decides readiness, the second is passed on its own,
 * and the remaining four fill the argument block above.  Same shape as the
 * siblings at 0207512c and 02074878, with a mixed-width block instead of a
 * plain int array. */
int Ov002_SubmitRequestBlockKind4(int pOwner, int pBlock)
{
    Ov002TaskArgsKind4 args;
    int nGate;
    int nFirst;
    int nB;
    int nC;
    int nD;
    int nE;

    nGate = ScriptVm_ReadOperandInt(pOwner, pBlock);
    nFirst = ScriptVm_ReadOperandInt(pOwner, pBlock + 8);
    nB = ScriptVm_ReadOperandInt(pOwner, pBlock + 0x10);
    nC = ScriptVm_ReadOperandInt(pOwner, pBlock + 0x18);
    nD = ScriptVm_ReadOperandInt(pOwner, pBlock + 0x20);
    nE = ScriptVm_ReadOperandInt(pOwner, pBlock + 0x28);

    args.bFirst = (u8)nB;
    args.bSecond = (u8)nC;
    args.nThird = nD;
    args.nFourth = nE;

    Ov002_SubmitTaskNode(nGate == 0, nFirst, 4, &args);
    return 1;
}
