
#include "nitro/types.h"
#include "game/engine.h"

typedef struct Ov002Piece {
    char pad000[0x1ac];
    u16 nFlags;             /* bit 2 takes the piece out of the test */
    char pad1ae[0x6a];
    s16 nSpan;
    s16 nLimit;
} Ov002Piece;

typedef struct Ov002Owner {
    char pad000[0x80];
    char list[0xc];
} Ov002Owner;

extern int Ov002_QueryEntryValue(int nIndex, int nFilter);
extern Ov002Owner *Ov002_GetPieceOwner(int nSlot);
extern Ov002Piece **List_First(void *pList);   /* first */

/* Says whether every piece still fits once its span is scaled by nScale, an
   fx32 factor.  A settled record set answers yes without looking at anything.
   A non-negative nFilter narrows the walk to that one owner slot; anything
   negative sweeps all eight. */
int Ov002_DoPiecesFitAtScale(int nFilter, int nScale)
{
    Ov002Piece **ppPiece;
    Ov002Piece *pPiece;
    int i;
    int bFits;
    Ov002Owner *pOwner;
    int nLast;
    int nScaled;

    i = 0;
    nLast = 8;
    bFits = 1;
    if (Ov002_QueryEntryValue(-1, nFilter) != -2) {
        return 1;
    }

    if (nFilter >= 0) {
        i = nFilter;
        nLast = nFilter + 1;
    }

    while (i < nLast) {
        pOwner = Ov002_GetPieceOwner(i);
        if (pOwner != 0) {
            ppPiece = List_First(pOwner->list);
            pPiece = (ppPiece == 0) ? 0 : *ppPiece;
            while (pPiece != 0) {
                if ((pPiece->nFlags & 4) == 0) {
                    nScaled = (nScale * pPiece->nSpan) >> 12;
                    if (nScale != 0 && nScaled == 0) {
                        nScaled = 1;
                    }
                    if (pPiece->nLimit > nScaled) {
                        bFits = 0;
                    }
                }
                ppPiece = List_Next(pOwner->list);
                pPiece = (ppPiece == 0) ? 0 : *ppPiece;
            }
        }
        i++;
    }
    return bFits;
}
