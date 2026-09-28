#pragma thumb on
/* Ov015_CreateSpotClass -- Ov015_CreateSpotClass: build the class table (0x184 bytes, ov002
 * 020769b0) that owns the 0x58-byte spot pieces from the script's table spec: for each spec
 * row {table, count, entries} the table (+0x58, 0x1c each) gets its links cleared (-1), its
 * two 64-bit id masks zeroed, its count, a heap copy of the entries (MI_CpuCopy8) and the id
 * bit of every entry ORed into the first (ids below 0x40) or second mask (runtime shift
 * 020203d0); then every table collects the distinct link targets (+0x14 of its kind-1
 * entries) into its four link bytes.  Handlers: free 020807cc (+0x4), 02080684 (+0xc),
 * drive 0208069c (+0x18), assign 02080ad0 (+0x20), 0208075c (+0x24), facing 02080794 (+0x28),
 * 02080734 (+0x2c), 0208073c (+0x30); class kind 0xe; the current entry pointer (+0x17c)
 * cleared, player (+0x180) and current entry (+0x179) -1, the link table (+0x178) 1 -- or 5 in
 * mission 0x25a (ov002 0206b84c).  Returns the table. */

#include "nitro/types.h"

typedef struct Ov015SpotEntry {
    s8  nId;                  /* 0x00 */
    s8  nKey;                 /* 0x01 */
    s8  nKind;                /* 0x02: 0 point, 1 link, 2 pickup */
    s8  aLink[4];             /* 0x03 */
    u8  pad_07[0x14 - 0x07];
    s8  nLinkTable;           /* 0x14 */
    s8  nLinkId;              /* 0x15 */
    u8  pad_16[2];
} Ov015SpotEntry;

typedef struct Ov015SpotTable {
    s8  nCount;               /* 0x00 */
    u8  pad_01[3];
    Ov015SpotEntry *aEntry;   /* 0x04 */
    u64 aMask[2];             /* 0x08: id bits 0..63 / 64..127 */
    s8  aLink[4];             /* 0x18: linked table ids, -1 = none */
} Ov015SpotTable;

typedef struct Ov015SpotDef {
    void *apHandler[0x13];    /* 0x000: class handler slots */
    u16  nKind;               /* 0x04c */
    u8   pad_04e[0x58 - 0x4e];
    Ov015SpotTable aTable[9]; /* 0x058 */
    u8   pad_154[0x178 - 0x154];
    s8   nLinkTable;          /* 0x178 */
    s8   nCurrent;            /* 0x179 */
    u8   pad_17a[2];
    Ov015SpotEntry *pCurrentEntry; /* 0x17c */
    s8   nPlayer;             /* 0x180 */
    u8   pad_181[3];
} Ov015SpotDef;

typedef struct Ov015SpotSpecRow {
    s8  nTable;               /* 0x00 */
    s8  nCount;               /* 0x01 */
    u8  pad_02[2];
    Ov015SpotEntry *aEntry;   /* 0x04 */
} Ov015SpotSpecRow;

typedef struct Ov015SpotSpec {
    s8  nRows;                /* 0x00 */
    u8  pad_01[3];
    Ov015SpotSpecRow aRow[1]; /* 0x04 */
} Ov015SpotSpec;

extern void *Ov002_CreateEntryPool(int headerSize, int entrySize, int count); /* build a class table */
extern void *NNSi_FndAllocFromDefaultExpHeap(u32 nSize);
extern void  MI_CpuCopy8(const void *pSrc, void *pDst, u32 nSize);
extern u64   func_020203d0(u64 nValue, int nShift);                             /* 64-bit shift left */
extern int   Ov002_GetStateWord(void);                                         /* current mission */
extern void  Ov015_FreeAllEntryBuffers(void);
extern void  Ov015_ClearBlock0x44(void);
extern void  Ov015_SpotDriveActor(void);
extern void  Ov015_SpotAssignPlayer(void);
extern void  Ov015_GetTargetIfInRange(void);
extern void  Ov015_SpotFacingForInteraction(void);
extern void  Ov015_AddrOfField0x30_2(void);
extern void  Ov015_Spot_SetPosition(void);

Ov015SpotDef *Ov015_CreateSpotClass(int nCount, Ov015SpotSpec *pSpec)
{
    int nId;
    int m;
    Ov015SpotDef *pDef;
    Ov015SpotSpecRow row;
    int bHigh;
    int k;
    Ov015SpotTable *pTable;
    int i;
    int nTable;
    char nLink;    /* the link id as a plain char (s8 codes differently), compared and stored in the table */
    int j;
    pDef = Ov002_CreateEntryPool(sizeof(Ov015SpotDef), 0x58, nCount);
    for (i = 0; i < pSpec->nRows; i++) {
        row = pSpec->aRow[i];
        nTable = row.nTable;
        pTable = &pDef->aTable[nTable];
        pTable->aLink[0] = -1;
        pTable->aLink[1] = -1;
        pTable->aLink[2] = -1;
        pTable->aLink[3] = -1;
        pTable->aMask[0] = 0;
        pTable->aMask[1] = 0;
        pTable->nCount = row.nCount;
        pTable->aEntry = NNSi_FndAllocFromDefaultExpHeap(row.nCount * sizeof(Ov015SpotEntry));
        MI_CpuCopy8(row.aEntry, pTable->aEntry, pTable->nCount * sizeof(Ov015SpotEntry));
        for (j = 0; j < pTable->nCount; j++) {
            bHigh = 0;
            nId = pTable->aEntry[j].nId;
            if (nId >= 0x40) {
                bHigh = 1;
                nId -= 0x40;
            }
            pTable->aMask[bHigh] |= 1ULL << nId;
        }
    }
    pTable = pDef->aTable;
    for (k = 0; k < 9; k++) {
        for (j = 0; j < pTable[k].nCount; j++) {
            if (pTable[k].aEntry[j].nKind == 1) {
                nId = pTable[k].aEntry[j].nLinkTable;
                nLink = nId;
                for (m = 0; m < 4; m++) {
                    if (nLink == pTable[k].aLink[m]) {
                        break;
                    }
                    if (pTable[k].aLink[m] == -1) {
                        pTable[k].aLink[m] = nLink;
                        break;
                    }
                }
            }
        }
    }
    pDef->apHandler[0] = 0;
    pDef->apHandler[1] = (void *)Ov015_FreeAllEntryBuffers;
    pDef->apHandler[2] = 0;
    pDef->apHandler[3] = (void *)Ov015_ClearBlock0x44;
    pDef->apHandler[4] = 0;
    pDef->apHandler[5] = 0;
    pDef->apHandler[6] = (void *)Ov015_SpotDriveActor;
    pDef->apHandler[7] = 0;
    pDef->apHandler[8] = (void *)Ov015_SpotAssignPlayer;
    pDef->apHandler[9] = (void *)Ov015_GetTargetIfInRange;
    pDef->apHandler[10] = (void *)Ov015_SpotFacingForInteraction;
    pDef->apHandler[11] = (void *)Ov015_AddrOfField0x30_2;
    pDef->apHandler[12] = (void *)Ov015_Spot_SetPosition;
    pDef->apHandler[14] = 0;
    pDef->apHandler[16] = 0;
    pDef->apHandler[17] = 0;
    pDef->apHandler[15] = 0;
    pDef->nKind = 0xe;
    pDef->pCurrentEntry = 0;
    pDef->nPlayer = -1;
    pDef->nCurrent = -1;
    pDef->nLinkTable = 1;
    if (Ov002_GetStateWord() == 0x25a) {
        pDef->nLinkTable = 5;
    }
    return pDef;
}
