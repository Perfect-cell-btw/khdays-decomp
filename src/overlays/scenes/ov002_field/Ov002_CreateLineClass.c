
/* The descriptor the caller fills in for one element class. */

#include "nitro/types.h"

typedef struct {
    const char *pName;              /* +0x00 */
    short nParam;                   /* +0x04 */
    signed char bLineCount;         /* +0x06 */
    const char *aLine[8];           /* +0x08 */
} Ov002LineClassDesc;

extern u8 data_0204c240;

extern void *Ov002_CreateEntryPool(int headerSize, int entrySize, int count);
extern char *strncpy(char *pDst, const char *pSrc, unsigned int nSize);
extern void Utf8_ToUcs2(const char *pNarrow, u16 *pWide);
extern int Wcslen(const u16 *pWide);
extern void *NNSi_FndAllocFromDefaultExpHeap(int nSize);
extern void StrNCopy16(u16 *pDst, const u16 *pSrc, int nLen);

extern void Ov002_FreeRowBuffers(void);
extern void Ov002_ActorElementHandleMessage(void);
extern void Ov002_Line_ReleaseNode(void);
extern void Ov002_RebindActorModelIfAlive(void);
extern void Ov002_ReleaseSceneResources(void);
extern void Ov002_ElementRestorePose(void);
extern void Ov002_BeginRequest(void);
extern void Ov002_AddrOfField0x1C_3(void);
extern void Ov002_GetWord28B(void);
extern void Ov002_AddrOfField0x1C_4(void);
extern void Ov002_SyncLitState(void);
extern void Ov002_Line_SetNodeEnabled(void);

/* Create the table that owns one class of line element.
 *
 * Allocates the 0x8c byte table together with room for 0x1c4 byte elements,
 * blanks the name and copies the descriptor's one over it when there is one,
 * then widens each of the class's lines into its own allocation. Both the line
 * work and the start handler are skipped when the global gate is closed.
 *
 * The counter shares an object with the widening buffer, and the buffer's
 * address escapes into the widening call, so the counter lives in memory the
 * way the original's does. The two volatile reads pin it there and fix the
 * order the exit test reads its two operands in; both are codegen tools, not
 * hardware accesses.
 */
void *Ov002_CreateLineClass(int nEntries, const Ov002LineClassDesc *pDesc)
{
    struct {
        volatile int nIndex;
        u16 aWide[256];
    } f;
    char *pTable;
    int nLen;
    void (*pfnStart)(void);
    int nCount;
    char *pSlot;
    const Ov002LineClassDesc *pWalk;

    pTable = (char *)Ov002_CreateEntryPool(0x8c, 0x1c4, nEntries);

    if (pDesc->pName == 0) {
        *(char *)(pTable + 0x58) = 0;
    } else {
        strncpy(pTable + 0x58, pDesc->pName, 0x10);
    }

    *(short *)(pTable + 0x68) = pDesc->nParam;
    *(signed char *)(pTable + 0x6a) = pDesc->bLineCount;

    if ((data_0204c240 & 4) == 0) {
        f.nIndex = 0;
        if (*(signed char *)(pTable + 0x6a) > 0) {
            pSlot = pTable;
            pWalk = pDesc;
            do {
                Utf8_ToUcs2(pWalk->aLine[0], f.aWide);
                nLen = Wcslen(f.aWide);
                *(u16 **)(pSlot + 0x6c) =
                    (u16 *)NNSi_FndAllocFromDefaultExpHeap((nLen + 1) * 2);
                StrNCopy16(*(u16 **)(pSlot + 0x6c), f.aWide, nLen);
                (*(u16 **)(pSlot + 0x6c))[nLen] = 0;
                f.nIndex++;
                pWalk = (const Ov002LineClassDesc *)((const char *)pWalk + 4);
                pSlot += 4;
                nCount = *(volatile signed char *)(pTable + 0x6a);
            } while (f.nIndex < nCount);
        }
    }

    *(u8 *)(pTable + 0x88) = 0;

    *(int *)(pTable + 0x00) = (int)Ov002_FreeRowBuffers;
    *(int *)(pTable + 0x04) = 0;
    *(int *)(pTable + 0x08) = (int)Ov002_ActorElementHandleMessage;
    *(int *)(pTable + 0x0c) = (int)Ov002_Line_ReleaseNode;
    *(int *)(pTable + 0x10) = (int)Ov002_RebindActorModelIfAlive;
    *(int *)(pTable + 0x14) = (int)Ov002_ReleaseSceneResources;
    *(int *)(pTable + 0x18) = (int)Ov002_ElementRestorePose;
    *(int *)(pTable + 0x1c) = 0;

    pfnStart = 0;
    if ((data_0204c240 & 4) == 0) {
        pfnStart = Ov002_BeginRequest;
    }
    *(int *)(pTable + 0x20) = (int)pfnStart;
    *(int *)(pTable + 0x24) = (int)Ov002_AddrOfField0x1C_3;
    *(int *)(pTable + 0x28) = (int)Ov002_GetWord28B;
    *(int *)(pTable + 0x2c) = (int)Ov002_AddrOfField0x1C_4;

    *(int *)(pTable + 0x38) = 0;
    *(int *)(pTable + 0x44) = 0;
    *(int *)(pTable + 0x48) = (int)Ov002_SyncLitState;
    *(int *)(pTable + 0x3c) = (int)Ov002_Line_SetNodeEnabled;
    *(u16 *)(pTable + 0x4c) = 9;

    return pTable;
}
