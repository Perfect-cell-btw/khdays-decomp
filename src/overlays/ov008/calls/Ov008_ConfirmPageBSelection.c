/* Ov008_ConfirmPageBSelection -- Ov008_ConfirmPageBSelection: accept the current entry of
 * page B once its list scroll has settled.  Ignored while the entry is busy or
 * inactive, or while the scroll cursor is still ahead of the row (the scroll's
 * total, from the ov025 list at +0x200, must not exceed row + 1).  Marks the page
 * as confirmed, then either initialises the global config for the entry (kind 0)
 * (the != 0 arm first: the -1 is derived from the confirm flag's 1) or targets the slot
 * with no explicit target, sets the entry's game flag
 * (0x3c2b + the page's flag base) and plays the confirm sound.
 */
typedef unsigned char u8;

typedef struct Ov008PageB {
    int nFlagBase;            /* 0x000 */
    int nEntry;               /* 0x004 */
    int nKind;                /* 0x008 */
    u8  pad_00c[0x1e8 - 0xc];
    int nRow;                 /* 0x1e8 */
    int bConfirmed;           /* 0x1ec */
    u8  pad_1f0[0x200 - 0x1f0];
    u8  list[4];              /* 0x200: ov025 list */
} Ov008PageB;

#define FLAG_PAGE_CONFIRM 0x3c2b
#define SOUND_CONFIRM     10

extern Ov008PageB *Ov008_GetPageB(void);              /* Ov008_GetPageB */
extern int Ov008_IsEntryBusyOrInactive(void);                      /* Ov008_IsEntryBusyOrInactive */
extern short Ov025_Res_GetCount(void *pList);             /* list scroll total */
extern void Ov008_SetTargetSlot(int nEntry, int nTarget);  /* Ov008_SetTargetSlot */
extern void Ov008_SetGlobalConfigAndInit(int nEntry);               /* Ov008_SetGlobalConfigAndInit */
extern void GameState_SetFlag(int nFlag);                      /* GameState_SetFlag */
extern void PlaySound(int nKind, int nSound);          /* PlaySound */
extern int data_ov008_02090a54[];                          /* page flag bases */

void Ov008_ConfirmPageBSelection(void)
{
    Ov008PageB *pPage = Ov008_GetPageB();

    if (Ov008_IsEntryBusyOrInactive() != 0) {
        return;
    }
    if (pPage->nRow + 1 < Ov025_Res_GetCount(pPage->list)) {
        return;
    }
    pPage->bConfirmed = 1;
    if (pPage->nKind != 0) {
        Ov008_SetTargetSlot(pPage->nEntry, -1);
    } else {
        Ov008_SetGlobalConfigAndInit(pPage->nEntry);
    }
    GameState_SetFlag(data_ov008_02090a54[pPage->nFlagBase] + FLAG_PAGE_CONFIRM);
    PlaySound(0, SOUND_CONFIRM);
}
