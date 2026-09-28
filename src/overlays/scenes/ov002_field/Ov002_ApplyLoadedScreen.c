/*
 * Ov002_ApplyLoadedScreen - stamp a finished screen load into the page's screen
 * and destroy the load node that carried it.
 *
 * The node's buffer holds an NSCR. Every entry inside a thirty-two by thirty-two
 * window is first biased by the page's tile base, in place in the resource
 * itself, and then each row is copied whole into item 0x1b's screen; rows past
 * the window are copied unbiased. While the page's manager block is absent the
 * node is destroyed and nothing is drawn.
 *
 * Four details are load-bearing. The tile counts divide by eight rather than
 * shift, which is what emits a logical shift instead of an arithmetic one on a
 * halfword the load already zero-extended. Each clamp reads value-first, so the
 * value arm falls through and the ceiling sits behind the branch. The row offset
 * stays written out as nRow * nCols at every use rather than accumulated into a
 * variable of its own: the compiler reduces it to an induction variable in the
 * first loop and materialises it once with a multiply in the second, which no
 * hand-written accumulator reproduces. And the entries pointer is declared ahead
 * of the screen pointer, which is what puts each of them in its own stack slot.
 *
 * Ghidra names the resolver findResourceNRCS and the node type Ov002LoadNode;
 * the externs keep their address symbols because that is what the delink
 * wires against.
 *
 * THUMB.
 */

#include "nitro/types.h"

typedef struct NNSG2dScreenData {
    u16 screenWidth;
    u16 screenHeight;
    u16 colorMode;
    u16 screenFormat;
    u32 szByte;
    u32 rawData[1];
} NNSG2dScreenData;

/* Ghidra carries the layout as Ov002LoadNode. */
typedef struct Ov002LoadNode {
    char pad000[8];
    void *pBuffer;
} Ov002LoadNode;

extern int data_ov002_0207f638;

extern void Ov002_DestroyOwnedEntry(Ov002LoadNode *pNode, int bFreeOwned);
extern int NNS_G2dGetUnpackedScreenData(void *pBuffer, void *ppOut);
extern u16 *Ov002_GetItemResource(int nItemId);
extern void Ov002_SelectEntry(int nItemId);
extern void MIi_CpuCopyFast(const void *pSrc, void *pDst, unsigned int nSize);

void Ov002_ApplyLoadedScreen(Ov002LoadNode *pNode)
{
    NNSG2dScreenData *pMap;
    u16 *pEntries;
    u16 *pScreen;
    int nCols;
    int nRows;
    int nWideCols;
    int nWideRows;
    int nRow;
    int nCol;

    if (data_ov002_0207f638 == 0) {
        Ov002_DestroyOwnedEntry(pNode, 1);
        return;
    }

    NNS_G2dGetUnpackedScreenData(pNode->pBuffer, &pMap);
    pScreen = Ov002_GetItemResource(0x1b);
    pEntries = (u16 *)pMap;
    pEntries = (u16 *)pMap->rawData;

    nCols = pMap->screenWidth / 8;
    nRows = pMap->screenHeight / 8;
    nWideCols = nCols <= 0x20 ? nCols : 0x20;
    nWideRows = nRows <= 0x20 ? nRows : 0x20;

    for (nRow = 0; nRow < nWideRows; nRow++) {
        for (nCol = 0; nCol < nWideCols; nCol++) {
            pEntries[nRow * nCols + nCol] =
                (u16)(pEntries[nRow * nCols + nCol] + 0x1cf);
        }
        MIi_CpuCopyFast(pEntries + nRow * nCols, pScreen + nRow * nCols,
                        nCols * 2);
    }

    for (; nRow < nRows; nRow++) {
        MIi_CpuCopyFast(pEntries + nRow * nCols, pScreen + nRow * nCols,
                        nCols * 2);
    }

    Ov002_SelectEntry(0x1b);
    Ov002_DestroyOwnedEntry(pNode, 1);
}
