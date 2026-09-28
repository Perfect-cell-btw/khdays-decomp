typedef unsigned short u16;

/* The descriptor the caller fills in for one timed-element class. */
typedef struct {
    const char *pName;              /* +0x00 */
    int nOwnerArg;                  /* +0x04 */
} Ov002TimedClassDesc;

extern void *Ov002_CreateEntryPool(int nTableSize, int nElementSize, void *pCtx);
extern char *strncpy(char *pDst, const char *pSrc, unsigned int nSize);

extern void Ov002_ReleaseEmbeddedNode_3(void);
extern void Ov002_RebindAnimatedActorModel(void);
extern void Ov002_Element_ReleaseNode(void);
extern void Ov002_ElementRebindModel(void);
extern void Ov002_ElementHandOverSlot(void);
extern void Ov002_GetField1cIfQueryBit1Clear(void);
extern void Ov002_GetField8Field68(void);
extern void Ov002_AddrOfField0xE0_3(void);
extern void Ov002_SetEmbeddedSceneNodeEnabled_2(void);

/* Create the table that owns one class of timed element.
 *
 * Allocates the 0x6c byte table together with room for 0x1bc byte elements,
 * blanks the name and copies the descriptor's one over it when there is one,
 * then installs the class's nine handlers.
 */
void *Ov002_CreateTimedClass(void *pCtx, const Ov002TimedClassDesc *pDesc)
{
    char *pTable;

    pTable = (char *)Ov002_CreateEntryPool(0x6c, 0x1bc, pCtx);

    *(unsigned char *)(pTable + 0x58) = 0;
    if (pDesc->pName != 0) {
        strncpy(pTable + 0x58, pDesc->pName, 0x10);
    }

    *(int *)(pTable + 0x68) = pDesc->nOwnerArg;

    *(int *)(pTable + 0x00) = 0;
    *(int *)(pTable + 0x04) = 0;
    *(int *)(pTable + 0x08) = 0;
    *(int *)(pTable + 0x0c) = (int)Ov002_ReleaseEmbeddedNode_3;
    *(int *)(pTable + 0x10) = (int)Ov002_RebindAnimatedActorModel;
    *(int *)(pTable + 0x14) = (int)Ov002_Element_ReleaseNode;
    *(int *)(pTable + 0x18) = (int)Ov002_ElementRebindModel;
    *(int *)(pTable + 0x1c) = 0;
    *(int *)(pTable + 0x20) = (int)Ov002_ElementHandOverSlot;
    *(int *)(pTable + 0x24) = (int)Ov002_GetField1cIfQueryBit1Clear;
    *(int *)(pTable + 0x28) = (int)Ov002_GetField8Field68;
    *(int *)(pTable + 0x2c) = (int)Ov002_AddrOfField0xE0_3;
    *(int *)(pTable + 0x38) = 0;
    *(int *)(pTable + 0x44) = 0;
    *(int *)(pTable + 0x3c) = (int)Ov002_SetEmbeddedSceneNodeEnabled_2;
    *(u16 *)(pTable + 0x4c) = 0xb;

    return pTable;
}
