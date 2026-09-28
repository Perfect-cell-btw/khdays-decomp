extern int ScriptVm_ReadOperandInt(int pOwner, int pSlot);
extern void Ov002_SubmitTaskNode(int bReady, int nFirst, int nKind, int *pRest);

/* Resolve the six slots of a request block and hand them to the builder:
 * the first slot only decides readiness, the second is passed on its own,
 * and the remaining four go through as an array.  Same shape as the sibling
 * at 0207512c, one slot wider and with a different node kind. */
int Ov002_SubmitRequestBlockKind1(int pOwner, int pBlock)
{
    int nRest[4];
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

    nRest[0] = nB;
    nRest[1] = nC;
    nRest[2] = nD;
    nRest[3] = nE;

    Ov002_SubmitTaskNode(nGate == 0, nFirst, 1, nRest);
    return 1;
}
