/* Ov008_MovePageBUp -- Ov008_MovePageBUp: move page B's cursor up one row.  Past
 * the top it wraps to the last row when a cue request is pending (else it stays on
 * row 0 and nothing else happens); a wrap that lands on row 0 is silent too.  Any
 * real move drains the double count for the new row, starts the collapse slide and
 * plays the move sound.
 */
#include "nitro/types.h"

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

extern Ov008PageB *Ov008_GetPageB(void);              /* Ov008_GetPageB */
extern int Ov008_IsEntryBusyOrInactive(void);                      /* Ov008_IsEntryBusyOrInactive */
extern Ov008CueRequest *Ov008_GetCueRequest(void);         /* Ov008_GetCueRequest */
extern short Ov025_Res_GetCount(void *pList);             /* list scroll total */
extern void Ov008_DrainDoubleCount(int nRow);                 /* Ov008_DrainDoubleCount */
extern void Ov008_InitOverlayFade(void);                     /* collapse slide */
extern void PlaySound(int nKind, int nSound);          /* PlaySound */

void Ov008_MovePageBUp(void)
{
    Ov008PageB *pPage = Ov008_GetPageB();
    int nRow;

    if (Ov008_IsEntryBusyOrInactive() != 0) {
        return;
    }
    nRow = pPage->nRow - 1;
    pPage->nRow = nRow;
    if (nRow < 0) {
        if (Ov008_GetCueRequest()->bWrap != 0) {
            nRow = Ov025_Res_GetCount(pPage->list) - 1;
            pPage->nRow = nRow;
            if (nRow == 0) {
                return;
            }
            Ov008_DrainDoubleCount(nRow);
            Ov008_InitOverlayFade();
            PlaySound(0, SOUND_MOVE);
        } else {
            pPage->nRow = 0;
        }
        return;
    }
    Ov008_DrainDoubleCount(nRow);
    Ov008_InitOverlayFade();
    PlaySound(0, SOUND_MOVE);
}
