/* Ov026_IsRecipeListed -- Ov008_IsRecipeListed: whether recipe nIndex of the
 * recipe table (+0x1c) shows up under the category filter nCategory (-1 = all):
 * the product's category must match, each of the first two ingredients (when
 * present) must have its item's "seen" flag (0x4db + item id) set, and the
 * product's item id must pass Ov026_IsRewardItemShown.  Returns 1 when listed.
 */

#include "nitro/types.h"

#define CATEGORY_ANY -1
#define FLAG_ITEM_SEEN_BASE 0x4db

typedef struct Ov008ItemDef {
    u8  pad_00[0x14];
    int nItemId;              /* 0x14 */
    int nCategory;            /* 0x18 */
} Ov008ItemDef;

typedef struct Ov008ItemStack {
    Ov008ItemDef *pItemDef;
    int           nCount;
} Ov008ItemStack;

typedef struct Ov008ParamRecord {
    u8              pad_00[0xc];
    Ov008ItemDef   *pItemDef;         /* 0x0c: product */
    int             nCount;           /* 0x10 */
    Ov008ItemStack  aIngredient[4];   /* 0x14 */
} Ov008ParamRecord;

typedef struct Ov008ParamTable {
    u8                pad_00[0x1c];
    Ov008ParamRecord *pRecipes;       /* 0x1c */
} Ov008ParamTable;

extern Ov008ParamTable *data_ov026_0209136c;
extern int GameState_IsFlagSet(int nFlag);                                    /* GameState_IsFlagSet */
extern int Ov026_IsRewardItemShown(int nItemId);                             /* item shown */

int Ov026_IsRecipeListed(int nCategory, int nIndex)
{
    Ov008ParamRecord *pRecipe;
    int bListed;
    int bIngredients;
    int bCategory;
    int bOk;

    pRecipe = &data_ov026_0209136c->pRecipes[nIndex];
    bListed = 0;
    bIngredients = 0;
    bCategory = 0;
    if (nCategory == CATEGORY_ANY || nCategory == pRecipe->pItemDef->nCategory) {
        bOk = 1;
        if (pRecipe->aIngredient[0].pItemDef != 0
            && GameState_IsFlagSet(pRecipe->aIngredient[0].pItemDef->nItemId + FLAG_ITEM_SEEN_BASE) == 0) {
            bOk = 0;
        }
        if (bOk) {
            bCategory = 1;
        }
    }
    if (bCategory) {
        bOk = 1;
        if (pRecipe->aIngredient[1].pItemDef != 0
            && GameState_IsFlagSet(pRecipe->aIngredient[1].pItemDef->nItemId + FLAG_ITEM_SEEN_BASE) == 0) {
            bOk = 0;
        }
        if (bOk) {
            bIngredients = 1;
        }
    }
    if (bIngredients && Ov026_IsRewardItemShown(pRecipe->pItemDef->nItemId) != 0) {
        bListed = 1;
    }
    return bListed;
}
