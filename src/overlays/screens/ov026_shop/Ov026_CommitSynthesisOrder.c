/* Ov026_CommitSynthesisOrder -- Ov008_ApplySynthesisResult: hand over the synthesised item
 * (stock + count, its "seen" flag, the recipe's unlock bit) and take the up to four
 * ingredient stacks out of the stock.
 */
#include "nitro/types.h"

#define INGREDIENT_COUNT 4
#define FLAG_ITEM_SEEN_BASE 0x4db

typedef struct Ov008ParamRecord {
    u8  pad_0000[0x14];
    int nId;                          /* 0x14 */
} Ov008ParamRecord;

typedef struct Ov008ItemStack {
    Ov008ParamRecord *pRecord;
    int               nCount;
} Ov008ItemStack;

typedef struct Ov008SynthRequest {
    int               pad_0000;
    u32               nUnlockBit;     /* 0x04 */
    int               pad_0008;
    Ov008ParamRecord *pRecord;        /* 0x0c */
    int               nCount;         /* 0x10 */
    Ov008ItemStack    aIngredient[INGREDIENT_COUNT]; /* 0x14 */
} Ov008SynthRequest;

typedef struct GameState {
    u8 pad_0000[0x810];
    u8 aItemCount[0x8d0];             /* 0x810 */
    u8 aUnlockBits[1];                /* 0x10e0 */
} GameState;

extern GameState *data_0204be18;
extern void GameState_SetFlag(int nFlag);              /* GameState_SetFlag */
extern void BitArray_SetBit(u8 *pBits, u32 nBit);     /* BitArray_SetBit */

void Ov026_CommitSynthesisOrder(Ov008SynthRequest *pReq)
{
    int i;

    data_0204be18->aItemCount[pReq->pRecord->nId] += pReq->nCount;
    GameState_SetFlag(pReq->pRecord->nId + FLAG_ITEM_SEEN_BASE);
    BitArray_SetBit(data_0204be18->aUnlockBits, pReq->nUnlockBit);
    for (i = 0; i < INGREDIENT_COUNT; i++) {
        if (pReq->aIngredient[i].nCount != 0) {
            data_0204be18->aItemCount[pReq->aIngredient[i].pRecord->nId] -= pReq->aIngredient[i].nCount;
        }
    }
}
