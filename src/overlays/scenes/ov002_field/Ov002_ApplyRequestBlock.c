extern int ScriptVm_ReadOperandInt(int pOwner, int pSlot);
extern void Ov002_BindLinkOptionBlock(int bThird, int nSecond, int nFirst, int nThird,
                                int bFifth);

/* Resolve the five slots of a request block and apply them. The fourth and
 * fifth slots are only tested for presence; the other three pass their values
 * through. */
int Ov002_ApplyRequestBlock(int pOwner, int pBlock)
{
    int nFirst;
    int nSecond;
    int nThird;
    int bFourth;
    int bFifth;

    nFirst = ScriptVm_ReadOperandInt(pOwner, pBlock);
    nSecond = ScriptVm_ReadOperandInt(pOwner, pBlock + 8);
    nThird = ScriptVm_ReadOperandInt(pOwner, pBlock + 0x10);
    bFourth = ScriptVm_ReadOperandInt(pOwner, pBlock + 0x18) != 0;
    bFifth = ScriptVm_ReadOperandInt(pOwner, pBlock + 0x20) != 0;

    Ov002_BindLinkOptionBlock(bFourth, nSecond, nFirst, nThird, bFifth);
    return 1;
}
