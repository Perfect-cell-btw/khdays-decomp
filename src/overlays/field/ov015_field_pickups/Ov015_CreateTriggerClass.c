/* Ov015_CreateTriggerClass -- Ov015_CreateTriggerClass: build the class table (0x58 bytes)
 * that owns the 0x5c-byte trigger pieces, install its four handlers in the slots every
 * piece class uses (arm 02080408, update 020804a4, 0208041c, hit test 02080424) and tag
 * it as class kind 0xd. */

#include "nitro/types.h"

extern void *Ov002_CreateEntryPool(int headerSize, int entrySize, int count);
extern void Ov015_SetByte0x50To2IfQ1(void);
extern void Ov015_TriggerUpdate(void);
extern void Ov015_AddrOfField0x30(void);
extern void Ov015_TriggerHitTest(void);

void *Ov015_CreateTriggerClass(int nCount, const void *pUnusedDesc)
{
    char *pTable;

    pTable = (char *)Ov002_CreateEntryPool(0x58, 0x5c, nCount);
    *(int *)(pTable + 0x00) = 0;
    *(int *)(pTable + 0x04) = 0;
    *(int *)(pTable + 0x08) = (int)Ov015_SetByte0x50To2IfQ1;
    *(int *)(pTable + 0x0c) = 0;
    *(int *)(pTable + 0x10) = 0;
    *(int *)(pTable + 0x14) = 0;
    *(int *)(pTable + 0x18) = 0;
    *(int *)(pTable + 0x1c) = (int)Ov015_TriggerUpdate;
    *(int *)(pTable + 0x20) = 0;
    *(int *)(pTable + 0x24) = 0;
    *(int *)(pTable + 0x28) = 0;
    *(int *)(pTable + 0x2c) = (int)Ov015_AddrOfField0x30;
    *(int *)(pTable + 0x38) = 0;
    *(int *)(pTable + 0x44) = (int)Ov015_TriggerHitTest;
    *(int *)(pTable + 0x3c) = 0;
    *(u16 *)(pTable + 0x4c) = 0xd;
    return pTable;
}
