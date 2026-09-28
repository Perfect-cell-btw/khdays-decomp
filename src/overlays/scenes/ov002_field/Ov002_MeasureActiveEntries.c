/* Walk the three entry slots at +0x7c4 of the block at data_ov002_0207f624, stopping at the first
 * empty one. Returns how many were active and writes the largest measured value through pnMax. Each
 * entry is passed to the measure helper as its third argument, alongside the shared source at
 * +0x6f0 and channel 0. */

extern int data_ov002_0207f624;

extern int NNSi_G2dFontGetTextWidth(int pSource, int nChannel, int nEntry);

int Ov002_MeasureActiveEntries(int *pnMax)
{
    int nCount;
    int i;
    int pSource;
    int *pOwner;
    int nMax;

    pOwner = *(int **)&data_ov002_0207f624;
    nMax = 0;
    pSource = pOwner[0x6f0 / 4];
    nCount = 0;

    for (i = 0; i < 3; i++) {
        int nValue;
        int nEntry;

        nEntry = pOwner[i + 0x7c4 / 4];
        if (nEntry == 0) {
            break;
        }

        nValue = NNSi_G2dFontGetTextWidth(pSource, 0, nEntry);
        if (nMax < nValue) {
            nMax = nValue;
        }
        nCount++;
    }

    *pnMax = nMax;
    return nCount;
}
