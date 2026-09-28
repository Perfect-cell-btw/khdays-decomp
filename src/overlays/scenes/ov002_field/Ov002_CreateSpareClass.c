#include "nitro/types.h"

/* The descriptor the caller fills in for one spare-entry class. */
typedef struct {
    u16 wStateField;                /* +0x00 */
    unsigned char bStateWidth;      /* +0x02 */
    unsigned char bWide;            /* +0x03 */
} Ov002SpareClassDesc;

extern void *Ov002_CreateEntryPool(int nTableSize, int nElementSize, void *pCtx);

extern void Ov002_SpareEntryHandleMessage(void);
extern void Ov002_SpareEntryTryBegin(void);
extern void Ov002_AddrOf0x1cIfLowNibbleSet(void);
extern void Ov002_GetWord28(void);
extern void Ov002_AddrOfField0x1C_2(void);

/* Create the table that owns one class of spare entry.
 *
 * Allocates the 0x5c byte table together with room for 0x48 byte entries, takes
 * the game-state field the class reports through, installs its five handlers
 * and picks the wide or narrow slot mask.
 */
void *Ov002_CreateSpareClass(void *pCtx, const Ov002SpareClassDesc *pDesc)
{
    char *pTable;

    pTable = (char *)Ov002_CreateEntryPool(0x5c, 0x48, pCtx);

    *(u16 *)(pTable + 0x58) = pDesc->wStateField;
    *(unsigned char *)(pTable + 0x5a) = pDesc->bStateWidth;

    *(int *)(pTable + 0x00) = 0;
    *(int *)(pTable + 0x04) = 0;
    *(int *)(pTable + 0x08) = (int)Ov002_SpareEntryHandleMessage;
    *(int *)(pTable + 0x0c) = 0;
    *(int *)(pTable + 0x10) = 0;
    *(int *)(pTable + 0x14) = 0;
    *(int *)(pTable + 0x18) = 0;
    *(int *)(pTable + 0x1c) = 0;
    *(int *)(pTable + 0x20) = (int)Ov002_SpareEntryTryBegin;
    *(int *)(pTable + 0x24) = (int)Ov002_AddrOf0x1cIfLowNibbleSet;
    *(int *)(pTable + 0x28) = (int)Ov002_GetWord28;
    *(int *)(pTable + 0x2c) = (int)Ov002_AddrOfField0x1C_2;
    *(int *)(pTable + 0x38) = 0;
    *(int *)(pTable + 0x44) = 0;
    *(int *)(pTable + 0x3c) = 0;
    *(u16 *)(pTable + 0x4c) = pDesc->bWide == 0 ? 8 : 0x20;

    return pTable;
}
