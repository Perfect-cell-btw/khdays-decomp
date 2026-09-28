
/* The descriptor the caller fills in for this class. */

#include "nitro/types.h"

typedef struct {
    int nOwnerArg;                  /* +0x00 */
    signed char bSlotKind;          /* +0x04 */
    unsigned char bPad0[3];         /* +0x05 */
    const char *pName;              /* +0x08 */
    signed char bKind;              /* +0x0c */
    unsigned char bPad1[3];         /* +0x0d */
    int nExtraA;                    /* +0x10 */
    int nExtraB;                    /* +0x14 */
    int nExtraC;                    /* +0x18 */
} Ov002PieceClassDesc;

extern void *Ov002_CreateEntryPool(int headerSize, int entrySize, int count);
extern char *strncpy(char *pDst, const char *pSrc, unsigned int nSize);

extern void Ov002_ReleaseEmbeddedNode_6(void);
extern void Ov002_RebindActorModelAndPalette(void);
extern void Ov002_Piece_ReleaseRenderItem(void);
extern void Ov002_ElementRestoreModel(void);
extern void Ov002_GetWordVia8Then0x68(void);
extern void Ov002_AddrOfField0xD0_2(void);
extern void Ov002_RecordMoveDelta(void);
extern void Ov002_AddrOfField0x1A4(void);
extern void Ov002_AddrOfField0x1C(void);
extern void Ov002_Element_SetNodeEnabled(void);

/* Create the table that owns one class of placed piece.
 *
 * Allocates the 0x7c byte table together with room for 0x1b0 byte elements,
 * blanks the name and copies the descriptor's one over it when there is one,
 * copies the rest of the descriptor, stamps the unset track marker and
 * installs the class's ten handlers.
 */
void *Ov002_CreatePieceClass_2(int nCount, const Ov002PieceClassDesc *pDesc)
{
    char *pTable;

    pTable = (char *)Ov002_CreateEntryPool(0x7c, 0x1b0, nCount);

    *(unsigned char *)(pTable + 0x58) = 0;
    if (pDesc->pName != 0) {
        strncpy(pTable + 0x58, pDesc->pName, 0x10);
    }

    *(signed char *)(pTable + 0x78) = pDesc->bKind;
    *(int *)(pTable + 0x6c) = pDesc->nExtraA;
    *(int *)(pTable + 0x70) = pDesc->nExtraB;
    *(int *)(pTable + 0x74) = pDesc->nExtraC;
    *(signed char *)(pTable + 0x79) = pDesc->bSlotKind;
    *(int *)(pTable + 0x68) = pDesc->nOwnerArg;
    *(signed char *)(pTable + 0x7a) = -1;

    *(int *)(pTable + 0x00) = 0;
    *(int *)(pTable + 0x04) = 0;
    *(int *)(pTable + 0x08) = 0;
    *(int *)(pTable + 0x0c) = (int)Ov002_ReleaseEmbeddedNode_6;
    *(int *)(pTable + 0x10) = (int)Ov002_RebindActorModelAndPalette;
    *(int *)(pTable + 0x14) = (int)Ov002_Piece_ReleaseRenderItem;
    *(int *)(pTable + 0x18) = (int)Ov002_ElementRestoreModel;
    *(int *)(pTable + 0x1c) = (int)Ov002_GetWordVia8Then0x68;
    *(int *)(pTable + 0x20) = 0;
    *(int *)(pTable + 0x24) = 0;
    *(int *)(pTable + 0x2c) = (int)Ov002_AddrOfField0xD0_2;
    *(int *)(pTable + 0x30) = (int)Ov002_RecordMoveDelta;
    *(int *)(pTable + 0x34) = (int)Ov002_AddrOfField0x1A4;
    *(int *)(pTable + 0x38) = 0;
    *(int *)(pTable + 0x40) = (int)Ov002_AddrOfField0x1C;
    *(int *)(pTable + 0x44) = 0;
    *(int *)(pTable + 0x3c) = (int)Ov002_Element_SetNodeEnabled;
    *(u16 *)(pTable + 0x4c) = 6;

    return pTable;
}
