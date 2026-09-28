/*
 * Ov002_PanelCursorStepLeft - move the panel cursor one column to the left.
 *
 * The mode says where "left" is. Two of the modes are already at the left edge
 * and do nothing; the two that sit one step in go back to mode 0; from the
 * first list the cursor returns to the grid, landing on the row the list was
 * opened over, unless the grid has nothing in it, in which case it goes home to
 * mode 0. Every other mode simply steps to the mode before it.
 *
 * THUMB.
 */

#include "nitro/types.h"

typedef struct {
    u8 pad0000;
    u8 bMode;                           /* +0x001 */
    u8 pad0002[0x4aa];
    u8 bListRowBase;                    /* +0x4ac */
} Ov002PanelSession;

extern Ov002PanelSession *data_ov002_0207f620;

extern int Ov002_CountPanelListEntries(void);
extern void Ov002_HandlePanelInput(int nTarget, int nValue);

void Ov002_PanelCursorStepLeft(void)
{
    Ov002PanelSession *s;

    s = data_ov002_0207f620;
    switch (s->bMode) {
    case 0:
    case 10:
        break;

    case 1:
    case 4:
        Ov002_HandlePanelInput(0, 2);
        return;

    case 6:
        if (Ov002_CountPanelListEntries() > 0) {
            Ov002_HandlePanelInput(s->bListRowBase + 3, 2);
            return;
        }
        Ov002_HandlePanelInput(0, 2);
        return;

    default:
        Ov002_HandlePanelInput(s->bMode - 1, 2);
        return;
    }
}
