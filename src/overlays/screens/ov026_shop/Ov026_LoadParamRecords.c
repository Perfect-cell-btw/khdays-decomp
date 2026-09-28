/* Ov026_LoadParamRecords -- Ov008_LoadParamRecords: load message db nDbId (slot 0xf),
 * allocate one 0x34-byte param record per db entry, and fill each record from
 * its raw db record through pfnFill(pRecord, pRaw, nIndex).  Db 0x15 is
 * 1-based and its raw records are not released after use; every other db is
 * 0-based and each raw record is freed.  Returns the db release result.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define DB_SLOT      0xf
#define DB_ONE_BASED 0x15

typedef struct Ov008ParamRecord {
    u8 pad_00[0x34];
} Ov008ParamRecord;

typedef void (*Ov008FillRecordFn)(Ov008ParamRecord *pRecord, void *pRaw, int nIndex);

extern void MsgDb_LoadDb(int nDbId, int nSlot);                        /* MsgDb_LoadDb */
extern u16 LoadArrayU16Stride14At0c(int nDbId);                                    /* record count */
extern void *NNSi_FndAllocFromDefaultExpHeap(u32 nSize);                /* AllocDefault (func_02023660) */
extern void MsgDb_FetchRecord(void **ppRaw, int nDbId, u32 nIndex, int nSlot); /* MsgDb_FetchRecord */
extern void DispatchByNodeKind(void **ppRaw);                                /* release a raw record */
extern int ResSlot_Release_2(int nDbId);                                    /* ResSlot_Release */

int Ov026_LoadParamRecords(u32 *pCount, Ov008ParamRecord **ppRecords, Ov008FillRecordFn pfnFill, int nDbId)
{
    u32 i;
    u32 nCount;
    void *pRaw;

    MsgDb_LoadDb(nDbId, DB_SLOT);
    nCount = LoadArrayU16Stride14At0c(nDbId);
    *pCount = nCount;
    *ppRecords = NNSi_FndAllocFromDefaultExpHeap(nCount * sizeof(Ov008ParamRecord));
    for (i = 0; i < nCount; i++) {
        pRaw = 0;
        MsgDb_FetchRecord(&pRaw, nDbId, i + (nDbId == DB_ONE_BASED ? 1 : 0), DB_SLOT);
        pfnFill(&(*ppRecords)[i], pRaw, i);
        if (nDbId != DB_ONE_BASED) {
            DispatchByNodeKind(&pRaw);
        }
    }
    return ResSlot_Release_2(nDbId);
}
