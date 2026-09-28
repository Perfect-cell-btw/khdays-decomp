extern int ScriptVm_ReadOperandInt(int pOwner, int pSlot);
extern void Ov002_SubmitTaskNode(int bReady, int nFirst, int nKind, int *pRest);

/* Resolve the five slots of a request block and hand them to the builder:
 * the first slot only decides readiness, the second is passed on its own,
 * and the remaining three go through as an array. */
int Ov002_SubmitRequestBlock(int pOwner, int pBlock)
{
    int nRest[3];
    int nGate;
    int nFirst;
    int nB;
    int nC;
    int nD;

    nGate = ScriptVm_ReadOperandInt(pOwner, pBlock);
    nFirst = ScriptVm_ReadOperandInt(pOwner, pBlock + 8);
    nB = ScriptVm_ReadOperandInt(pOwner, pBlock + 0x10);
    nC = ScriptVm_ReadOperandInt(pOwner, pBlock + 0x18);
    nD = ScriptVm_ReadOperandInt(pOwner, pBlock + 0x20);

    nRest[0] = nB;
    nRest[1] = nC;
    nRest[2] = nD;

    Ov002_SubmitTaskNode(nGate == 0, nFirst, 5, nRest);
    return 1;
}
