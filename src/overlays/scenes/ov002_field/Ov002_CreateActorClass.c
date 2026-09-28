
/* The descriptor the caller fills in for one actor-element class. */

#include "nitro/types.h"

typedef struct {
    const char *pName;              /* +0x00 */
    short nParamA;                  /* +0x04 */
    short nParamB;                  /* +0x06 */
    short nParamC;                  /* +0x08 */
    short nPad;                     /* +0x0a */
    int nExtraA;                    /* +0x0c */
    int nExtraB;                    /* +0x10 */
    signed char bKind;              /* +0x14 */
} Ov002ActorClassDesc;

extern void *Ov002_CreateEntryPool(int nTableSize, int nElementSize, void *pCtx);
extern char *strncpy(char *pDst, const char *pSrc, unsigned int nSize);

extern void Ov002_Element_OnFinishMessage(void);
extern void Ov002_ReleaseEmbeddedNode_5(void);
extern void Ov002_RebindActorModel_2(void);
extern void Ov002_Actor_ReleaseRenderItem(void);
extern void Ov002_ElementRebuildVisuals(void);
extern void Ov002_AddrOfField0xD0(void);
extern void Ov002_Actor_SetNodeEnabled(void);

/* Create the table that owns one class of actor element.
 *
 * Allocates the 0x84 byte table together with room for 0x1d4 byte elements,
 * copies the descriptor's fields into it - the name only when there is one -
 * and installs the class's seven handlers.
 */
void *Ov002_CreateActorClass(void *pCtx, const Ov002ActorClassDesc *pDesc)
{
    char *pTable;

    pTable = (char *)Ov002_CreateEntryPool(0x84, 0x1d4, pCtx);

    if (pDesc->pName != 0) {
        strncpy(pTable + 0x58, pDesc->pName, 0x10);
    }

    *(short *)(pTable + 0x68) = pDesc->nParamA;
    *(short *)(pTable + 0x6a) = pDesc->nParamB;
    *(short *)(pTable + 0x6c) = pDesc->nParamC;
    *(signed char *)(pTable + 0x80) = pDesc->bKind;
    *(int *)(pTable + 0x7c) = pDesc->nExtraA;
    *(int *)(pTable + 0x74) = pDesc->nExtraB;

    *(int *)(pTable + 0x00) = 0;
    *(int *)(pTable + 0x04) = 0;
    *(int *)(pTable + 0x08) = (int)Ov002_Element_OnFinishMessage;
    *(int *)(pTable + 0x0c) = (int)Ov002_ReleaseEmbeddedNode_5;
    *(int *)(pTable + 0x10) = (int)Ov002_RebindActorModel_2;
    *(int *)(pTable + 0x14) = (int)Ov002_Actor_ReleaseRenderItem;
    *(int *)(pTable + 0x18) = (int)Ov002_ElementRebuildVisuals;
    *(int *)(pTable + 0x1c) = 0;
    *(int *)(pTable + 0x20) = 0;
    *(int *)(pTable + 0x24) = 0;
    *(int *)(pTable + 0x2c) = (int)Ov002_AddrOfField0xD0;
    *(int *)(pTable + 0x38) = 0;
    *(int *)(pTable + 0x44) = 0;
    *(int *)(pTable + 0x3c) = (int)Ov002_Actor_SetNodeEnabled;
    *(u16 *)(pTable + 0x4c) = 5;

    return pTable;
}
