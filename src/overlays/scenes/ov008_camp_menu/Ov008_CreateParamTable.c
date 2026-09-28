/* Ov008_CreateParamTable -- Ov008_CreateParamTable: allocate and zero the 0x158-byte
 * param table (data_ov008_02090fb0) and load its five record lists from the
 * message dbs: shop (0x15, Ov008_FillShopRecord), 0x20 (Ov008_FillItemListRecord),
 * recipes (0x1f, Ov008_FillRecipeRecord) and the two reward lists (0x18 / 0x17,
 * Ov008_FillRewardRecord).  Points the two pending unlock bit arrays at the
 * table's own 0x80-byte blocks (+0x3c, +0xbc) and the two committed arrays at
 * the game state's blocks (0xfe0, 0x1060), sets bShowAll when GameState field
 * 0x44e is 6, and runs the post-load pass (02089e94).
 */

#include "nitro/types.h"

#define LIST_COUNT      5
#define BIT_ARRAY_COUNT 2
#define BIT_ARRAY_WORDS 32
#define FIELD_RANK      0x44e
#define RANK_SHOW_ALL   6
#define DB_SHOP         0x15
#define DB_ITEM_LIST    0x20
#define DB_RECIPES      0x1f
#define DB_REWARDS_A    0x18
#define DB_REWARDS_B    0x17

typedef struct Ov008ParamRecord {
    u8 pad_00[0x34];
} Ov008ParamRecord;

typedef void (*Ov008FillRecordFn)(Ov008ParamRecord *pRecord, void *pRaw, int nIndex);

typedef struct Ov008ParamTable {
    u32               aCount[LIST_COUNT];                 /* 0x000 */
    Ov008ParamRecord *apRecords[LIST_COUNT];              /* 0x014 */
    u32              *apPendingBits[BIT_ARRAY_COUNT];     /* 0x028 */
    u32              *apUnlockBits[BIT_ARRAY_COUNT];      /* 0x030 */
    u8                pad_038[4];
    u32               aPendingBits[BIT_ARRAY_COUNT][BIT_ARRAY_WORDS]; /* 0x03c */
    u32               aPendingSummary[BIT_ARRAY_COUNT];   /* 0x13c */
    int               bShowAll;                           /* 0x144 */
    u8                pad_148[0x158 - 0x148];
} Ov008ParamTable;

typedef struct GameState {
    u8  pad_0000[0xfe0];
    u32 aUnlockBits[BIT_ARRAY_COUNT][BIT_ARRAY_WORDS];   /* 0xfe0 */
} GameState;

extern Ov008ParamTable *data_ov008_02090fb0;
extern GameState *data_0204be18;
extern void *NNSi_FndAllocFromDefaultExpHeap(u32 nSize);                /* AllocDefault */
extern void  MI_CpuFill8(void *pDst, int nValue, u32 nSize);
extern int   Ov008_LoadParamRecords(u32 *pCount, Ov008ParamRecord **ppRecords, Ov008FillRecordFn pfnFill, int nDbId); /* Ov008_LoadParamRecords */
extern void  Ov008_InitSlotFromSource(Ov008ParamRecord *pRecord, void *pRaw, int nIndex);   /* shop record */
extern void  Ov008_BuildSlotPacketA(Ov008ParamRecord *pRecord, void *pRaw, int nIndex);   /* item list record */
extern void  Ov008_BuildSlotPacketB(Ov008ParamRecord *pRecord, void *pRaw, int nIndex);   /* recipe record */
extern void  Ov008_FillRewardRecord(Ov008ParamRecord *pRecord, void *pRaw, int nIndex);   /* reward record */
extern u32   GameState_GetField(int nField, int nBits);                       /* GameState_GetField */
extern void  Ov008_RefreshShopUnlockParams(void);                                  /* post-load pass */

void Ov008_CreateParamTable(void)
{
    data_ov008_02090fb0 = NNSi_FndAllocFromDefaultExpHeap(sizeof(Ov008ParamTable));
    MI_CpuFill8(data_ov008_02090fb0, 0, sizeof(Ov008ParamTable));
    Ov008_LoadParamRecords(&data_ov008_02090fb0->aCount[0], &data_ov008_02090fb0->apRecords[0], Ov008_InitSlotFromSource, DB_SHOP);
    Ov008_LoadParamRecords(&data_ov008_02090fb0->aCount[1], &data_ov008_02090fb0->apRecords[1], Ov008_BuildSlotPacketA, DB_ITEM_LIST);
    Ov008_LoadParamRecords(&data_ov008_02090fb0->aCount[2], &data_ov008_02090fb0->apRecords[2], Ov008_BuildSlotPacketB, DB_RECIPES);
    Ov008_LoadParamRecords(&data_ov008_02090fb0->aCount[3], &data_ov008_02090fb0->apRecords[3], Ov008_FillRewardRecord, DB_REWARDS_A);
    Ov008_LoadParamRecords(&data_ov008_02090fb0->aCount[4], &data_ov008_02090fb0->apRecords[4], Ov008_FillRewardRecord, DB_REWARDS_B);
    data_ov008_02090fb0->apPendingBits[0] = data_ov008_02090fb0->aPendingBits[0];
    data_ov008_02090fb0->apPendingBits[1] = data_ov008_02090fb0->aPendingBits[1];
    data_ov008_02090fb0->apUnlockBits[0] = data_0204be18->aUnlockBits[0];
    data_ov008_02090fb0->apUnlockBits[1] = data_0204be18->aUnlockBits[1];
    data_ov008_02090fb0->bShowAll = GameState_GetField(FIELD_RANK, 3) == RANK_SHOW_ALL;
    Ov008_RefreshShopUnlockParams();
}
