/* Ov008_CommitSynthesisOrder -- Ov008_CommitSynthesisOrder: hand over the synthesised item
 * (stock + count, its "seen" flag, the recipe's unlock bit) and take the up to four
 * ingredient stacks out of the stock.
 */

#include "nitro/types.h"
#include "game/engine.h"

#define INGREDIENT_COUNT 4
#define FLAG_ITEM_SEEN_BASE 0x4db

typedef struct Ov008ItemDef {
    u8  pad_0000[0x14];
    int nItemId;                      /* 0x14 */
} Ov008ItemDef;

typedef struct Ov008ItemStack {
    Ov008ItemDef *pItemDef;
    int           nCount;
} Ov008ItemStack;

typedef struct Ov008RecipeRecord {                  /* synthesis recipe */
    int               pad_0000;
    u32               nUnlockBit;     /* 0x04 */
    int               nPrice;         /* 0x08 */
    Ov008ItemDef     *pItemDef;       /* 0x0c: product */
    int               nCount;         /* 0x10 */
    Ov008ItemStack    aIngredient[INGREDIENT_COUNT]; /* 0x14 */
} Ov008RecipeRecord;

typedef struct GameState {
    u8 pad_0000[0x810];
    u8 aItemCount[0x8d0];             /* 0x810 */
    u8 aUnlockBits[1];                /* 0x10e0 */
} GameState;

extern GameState *gGameState;
extern void BitArray_SetBit(u8 *pBits, u32 nBit);     /* BitArray_SetBit */

void Ov008_CommitSynthesisOrder(Ov008RecipeRecord *pRecipe)
{
    int i;

    gGameState->aItemCount[pRecipe->pItemDef->nItemId] += pRecipe->nCount;
    GameState_SetFlag(pRecipe->pItemDef->nItemId + FLAG_ITEM_SEEN_BASE);
    BitArray_SetBit(gGameState->aUnlockBits, pRecipe->nUnlockBit);
    for (i = 0; i < INGREDIENT_COUNT; i++) {
        if (pRecipe->aIngredient[i].nCount != 0) {
            gGameState->aItemCount[pRecipe->aIngredient[i].pItemDef->nItemId] -= pRecipe->aIngredient[i].nCount;
        }
    }
}
