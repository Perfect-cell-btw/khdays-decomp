/* Ov008_ToggleOptionFlag -- Ov008_ToggleOptionFlag: flip game flag 0x2010 from the
 * options list.  With the "reverse" word (+0x1fa4) set the flag is cleared when
 * it was set (target slot 0 -> -1) or set otherwise; without it the polarity is
 * the other way round.  Then, unless a transfer is pending, rebinds the three
 * list callbacks and plays the confirm cue.
 */
#include "nitro/types.h"

typedef struct Ov008MenuContext {
    u8   pad_0000[0x30];
    int  nTransferPending;   /* 0x30 */
    u8   pad_0034[0x1fa4 - 0x34];
    int  bReverse;           /* 0x1fa4 */
} Ov008MenuContext;

typedef struct Ov008ListHooks {
    u8   pad_00[0x14];
    void (*pfnSelect)(void); /* 0x14 */
    void (*pfnCancel)(void); /* 0x18 */
    u8   pad_1c[8];
    void (*pfnDone)(void);   /* 0x24 */
} Ov008ListHooks;

#define FLAG_OPTION 0x2010
#define NO_TARGET   -1

extern Ov008MenuContext *Ov008_GetMenuContext(void);            /* Ov008_GetMenuContext */
extern int GameState_IsFlagSet(int nFlag);                            /* GameState_IsFlagSet */
extern void GameState_SetFlag(int nFlag);                           /* GameState_SetFlag */
extern void func_020235bc(int nFlag);                           /* GameState_ClearFlag */
extern void Ov008_SetTargetSlot(int nEntry, int nTarget);       /* Ov008_SetTargetSlot */
extern void PlaySound(int nKind, int nArg);                 /* PlaySound */
extern void Ov008_GridMenuConfirm(void);
extern void Ov008_MenuKeyUp(void);
extern void Ov008_MenuKeyDown(void);
extern Ov008ListHooks data_ov008_02090380;

void Ov008_ToggleOptionFlag(void)
{
    Ov008MenuContext *pCtx = Ov008_GetMenuContext();

    if (pCtx->bReverse != 0) {
        if (GameState_IsFlagSet(FLAG_OPTION) == 0) {
            Ov008_SetTargetSlot(-1, NO_TARGET);
        } else {
            Ov008_SetTargetSlot(0, NO_TARGET);
        }
        GameState_SetFlag(FLAG_OPTION);
    } else {
        if (GameState_IsFlagSet(FLAG_OPTION) != 0) {
            Ov008_SetTargetSlot(-1, NO_TARGET);
        } else {
            Ov008_SetTargetSlot(0, NO_TARGET);
        }
        func_020235bc(FLAG_OPTION);
    }
    if (pCtx->nTransferPending != 0) {
        return;
    }
    data_ov008_02090380.pfnDone = Ov008_GridMenuConfirm;
    data_ov008_02090380.pfnSelect = Ov008_MenuKeyUp;
    data_ov008_02090380.pfnCancel = Ov008_MenuKeyDown;
    PlaySound(0, 1);
}
