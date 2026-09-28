/* Ov025_MovePageBDown -- Ov008_MovePageBDown: move page B's cursor down one row.
 * With a cue request pending the row advances and wraps to 0 past the end (the
 * wrap resets the ov025 list, and is silent when the list has fewer than two
 * rows); without one the row only advances while a row below exists.  Any real
 * move starts the collapse slide and plays the move sound.
 */
typedef unsigned char u8;

typedef struct Ov008PageB {
    u8  pad_000[0x1e8];
    int nRow;                 /* 0x1e8 */
    u8  pad_1ec[0x200 - 0x1ec];
    u8  list[4];              /* 0x200: ov025 list */
} Ov008PageB;

typedef struct Ov008CueRequest {
    u8  pad_00[0xc];
    int bWrap;                /* 0x0c */
} Ov008CueRequest;

#define SOUND_MOVE 2

extern Ov008PageB *Ov025_GetPageB(void);              /* Ov008_GetPageB */
extern int Ov025_IsEntryBusyOrInactive(void);                      /* Ov008_IsEntryBusyOrInactive */
extern Ov008CueRequest *Ov025_GetCueRequest(void);         /* Ov008_GetCueRequest */
extern short Ov025_Res_GetCount(void *pList);             /* list scroll total */
extern void Ov025_Res_BindSecondBlock(void *pList);              /* list reset */
extern void Ov025_InitOverlayFade(void);                     /* collapse slide */
extern void PlaySound(int nKind, int nSound);          /* PlaySound */

void Ov025_MovePageBDown(void)
{
    Ov008PageB *pPage = Ov025_GetPageB();

    if (Ov025_IsEntryBusyOrInactive() != 0) {
        return;
    }
    if (Ov025_GetCueRequest()->bWrap != 0) {
        pPage->nRow++;
        if (pPage->nRow >= Ov025_Res_GetCount(pPage->list)) {
            pPage->nRow = 0;
            /* unsigned `> 1`: the ROM tests the total with cmp #1 / popls */
            if ((unsigned int)(int)Ov025_Res_GetCount(pPage->list) > 1) {
                Ov025_Res_BindSecondBlock(pPage->list);
                Ov025_InitOverlayFade();
                PlaySound(0, SOUND_MOVE);
            }
        } else {
            Ov025_InitOverlayFade();
            PlaySound(0, SOUND_MOVE);
        }
    } else {
        if (pPage->nRow + 1 < Ov025_Res_GetCount(pPage->list)) {
            Ov025_InitOverlayFade();
            PlaySound(0, SOUND_MOVE);
            pPage->nRow++;
        }
    }
}
