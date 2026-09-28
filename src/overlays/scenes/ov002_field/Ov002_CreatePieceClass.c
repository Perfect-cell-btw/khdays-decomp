typedef unsigned short u16;

/* What the caller hands over to describe one class of piece. */
typedef struct {
    const char *pName;              /* +0x00 */
    short nSlotA;                   /* +0x04 */
    short nSlotB;                   /* +0x06 */
    int nReplayLimit;               /* +0x08 */
    int nClockLimit;                /* +0x0c */
    signed char bKind;              /* +0x10 */
    signed char bVariant;           /* +0x11 */
    short nParamA;                  /* +0x12 */
    short nParamB;                  /* +0x14 */
    short nParamC;                  /* +0x16 */
    int nExtraC;                    /* +0x18, not read here */
} Ov002PieceClassDesc;              /* 0x1c */

extern void *Ov002_CreateEntryPool(int nTableSize, int nElementSize, void *pCtx);
extern char *strncpy(char *pDst, const char *pSrc, unsigned int nSize);

extern void Ov002_SetBit0OfByte0x1b6(void);
extern void Ov002_ReleaseEmbeddedNode(void);
extern void Ov002_RebindActorModelByKind(void);
extern void Ov002_RefreshEntryIfLive(void);
extern void Ov002_BuildPieceNode(void);
extern void Ov002_TryRegisterElementHit(void);
extern void Ov002_AddrOf0x1cIfBit0Clear(void);
extern void Ov002_GetWordVia8Then0x70(void);
extern void Ov002_AddrOfField0xE0(void);
extern void Ov002_SetEmbeddedSceneNodeEnabled(void);

/* Create the table that owns one class of piece.
 *
 * Allocates the 0x7c byte table together with room for 0x1b8 byte elements,
 * copies the class name and the descriptor's fields into it, and installs the
 * class's ten handlers in the same slots every element class uses.
 *
 * The variant byte at +0x75 is written last, after the three shorts that sit
 * above it, which is the order the ROM stores them in.
 */
void *Ov002_CreatePieceClass(void *pCtx, const Ov002PieceClassDesc *pDesc)
{
    char *pTable;

    pTable = (char *)Ov002_CreateEntryPool(0x7c, 0x1b8, pCtx);

    strncpy(pTable + 0x58, pDesc->pName, 0x10);

    *(short *)(pTable + 0x68) = pDesc->nSlotA;
    *(short *)(pTable + 0x6a) = pDesc->nSlotB;
    *(int *)(pTable + 0x6c) = pDesc->nReplayLimit;
    *(int *)(pTable + 0x70) = pDesc->nClockLimit;
    *(signed char *)(pTable + 0x74) = pDesc->bKind;
    *(short *)(pTable + 0x76) = pDesc->nParamA;
    *(short *)(pTable + 0x78) = pDesc->nParamB;
    *(short *)(pTable + 0x7a) = pDesc->nParamC;
    *(signed char *)(pTable + 0x75) = pDesc->bVariant;

    *(int *)(pTable + 0x00) = 0;
    *(int *)(pTable + 0x04) = 0;
    *(int *)(pTable + 0x08) = (int)Ov002_SetBit0OfByte0x1b6;
    *(int *)(pTable + 0x0c) = (int)Ov002_ReleaseEmbeddedNode;
    *(int *)(pTable + 0x10) = (int)Ov002_RebindActorModelByKind;
    *(int *)(pTable + 0x14) = (int)Ov002_RefreshEntryIfLive;
    *(int *)(pTable + 0x18) = (int)Ov002_BuildPieceNode;
    *(int *)(pTable + 0x1c) = (int)Ov002_TryRegisterElementHit;
    *(int *)(pTable + 0x20) = 0;
    *(int *)(pTable + 0x24) = (int)Ov002_AddrOf0x1cIfBit0Clear;
    *(int *)(pTable + 0x28) = (int)Ov002_GetWordVia8Then0x70;
    *(int *)(pTable + 0x2c) = (int)Ov002_AddrOfField0xE0;
    *(int *)(pTable + 0x38) = 0;
    *(int *)(pTable + 0x44) = 0;
    *(int *)(pTable + 0x3c) = (int)Ov002_SetEmbeddedSceneNodeEnabled;
    *(u16 *)(pTable + 0x4c) = 0;

    return pTable;
}
