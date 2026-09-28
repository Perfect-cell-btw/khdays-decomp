/* Ov017_ScriptOpRetirePiece -- Ov017_ScriptOpRetirePiece: script op that resolves the piece named
 * by its two operands (key and argument, ov002 0207679c) and retires it: an item piece (class
 * kinds 0x1d / 0x1e) through Ov017_ItemRetire (02080a60), any other through the kind dispatch
 * Ov017_RetireByKind (020804b4).  Always 1. */

#include "nitro/types.h"

typedef struct Ov017PieceDef {
    u8   pad_00[0x4c];
    u16  nKind;               /* 0x4c */
} Ov017PieceDef;

typedef struct Ov017Piece {
    u8   pad_00[8];
    Ov017PieceDef *pDef;      /* 0x08 */
} Ov017Piece;

extern int   ScriptVm_ReadOperandInt(int vm, u16 *pc);                          /* ScriptVm_ReadOperandInt */
extern Ov017Piece *Ov002_List_ScaleEntryTag(int nKey, int nArg);           /* resolve a piece */
extern void  Ov017_ForwardToHandler(Ov017Piece *pPiece);                 /* Ov017_ItemRetire */
extern void  Ov017_DispatchOnField4c(Ov017Piece *pPiece);                 /* Ov017_RetireByKind */

int Ov017_ScriptOpRetirePiece(int vm, u16 *pc)
{
    int nKey;
    int nArg;
    Ov017Piece *pPiece;

    nKey = ScriptVm_ReadOperandInt(vm, pc);
    nArg = ScriptVm_ReadOperandInt(vm, pc + 4);
    pPiece = Ov002_List_ScaleEntryTag(nKey & 0xff, nArg & 0xffff);
    if ((u16)(pPiece->pDef->nKind + 0xffe3) <= 1) {
        Ov017_ForwardToHandler(pPiece);
    } else {
        Ov017_DispatchOnField4c(pPiece);
    }
    return 1;
}
