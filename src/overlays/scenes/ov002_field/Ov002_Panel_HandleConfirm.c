/*
 * Ov002_PanelStepCursorBack - move the panel cursor back up one row, or refuse.
 *
 * What "back up" means again depends on what the current mode classifies as.
 * From the top of the slot ring the cursor either goes to row 1, or, when the
 * first cell is empty, the move is refused with a buzz. From the top of the
 * grid it hands over to whichever list has entries. Inside the grid or either
 * list it just steps to the previous row, and the second list is offered as the
 * fallback when the first one has run out above.
 *
 * Every path that does move asks for direction 2; the ones that cannot simply
 * return, which is why so many of the arms end in their own epilogue.
 *
 * THUMB.
 */

#include "nitro/types.h"

typedef struct {
    u8 bKind;                           /* +0x000 */
    u8 bMode;                           /* +0x001 */
    u8 pad0002[0x2f];
    u8 bCursorRow;                      /* +0x031 */
    u8 aCells[0x47a];                   /* +0x032 */
    u8 bListRowBase;                    /* +0x4ac */
    u8 bListRowOffset;                  /* +0x4ad */
} Ov002PanelSession;

extern Ov002PanelSession *data_ov002_0207f620;

extern void PlaySoundChecked(int nId, int nKind);

extern int Ov002_ClassifyCode(int *pOut, int nIndex);
extern int Ov002_CountPanelListEntries(void);
extern int Ov002_CountSecondListEntries(void);
extern void Ov002_HandlePanelInput(int nTarget, int nValue);

void Ov002_Panel_HandleConfirm(void)
{
    Ov002PanelSession *s;
    int nRow;

    s = data_ov002_0207f620;
    switch (Ov002_ClassifyCode(&nRow, s->bMode)) {
    case 0:
        switch (s->bKind) {
        case 1:
            if (s->aCells[0] == 0xff) {
                PlaySoundChecked(0, 4);
                return;
            }
            Ov002_HandlePanelInput(1, 2);
            return;
        case 2:
            if (Ov002_CountPanelListEntries() > 0) {
                Ov002_HandlePanelInput(4, 2);
                return;
            }
            if (Ov002_CountSecondListEntries() > 0) {
                Ov002_HandlePanelInput(6, 2);
                return;
            }
            break;
        }
        break;

    case 1:
        if (nRow + 1 < s->bCursorRow) {
            Ov002_HandlePanelInput(s->bMode + 1, 2);
            return;
        }
        break;

    case 2:
        if (nRow >= s->bListRowBase - 1) {
            if (Ov002_CountSecondListEntries() > 0) {
                Ov002_HandlePanelInput(6, 2);
                return;
            }
            break;
        }
        Ov002_HandlePanelInput(s->bMode + 1, 2);
        return;

    case 3:
        if (nRow + 1 < s->bListRowOffset) {
            Ov002_HandlePanelInput(s->bMode + 1, 2);
        }
        break;
    }
}
