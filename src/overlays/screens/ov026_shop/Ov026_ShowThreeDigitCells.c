/* Ov026_ShowThreeDigitCells -- Ov008_ShowThreeDigitCells: show a number (clamped to
 * 999) on three digit cells.  Shows widgets 0x1e and 0x1f of the widget group
 * (ctx+0x7530), then from the units cell (index 2) up: a digit cell is shown
 * with its digit frame (value % 10) while the value is non-zero, the units cell
 * always; leading cells with nothing left are hidden.
 */

#include "nitro/types.h"

#define VALUE_MAX 999
#define DIGIT_CELLS 3
#define WIDGET_DIGITS_A 0x1e
#define WIDGET_DIGITS_B 0x1f

extern char *data_ov026_02091368;
extern void *Ov026_FindEntryById(void *pGroup, int nId);                 /* FindEntryById */
extern void Ov026_SetEntrySlotsVisible(void *pGroup, void *pWidget, int bVisible); /* SetEntrySlotsVisible */
extern void Slot_SetVisible(int hSlots, int nCell, int bVisible);           /* Slot_SetVisible */
extern void Slot_ForwardToEntry(int hSlots, int nCell, int nFrame);             /* Slot_ForwardToEntry */

void Ov026_ShowThreeDigitCells(int hSlots, u32 nValue, int *aCell)
{
    char *pGroup = data_ov026_02091368 + 0x7530;
    int i;

    if (nValue > VALUE_MAX) {
        nValue = VALUE_MAX;
    }
    Ov026_SetEntrySlotsVisible(pGroup, Ov026_FindEntryById(pGroup, WIDGET_DIGITS_A), 1);
    Ov026_SetEntrySlotsVisible(pGroup, Ov026_FindEntryById(pGroup, WIDGET_DIGITS_B), 1);
    for (i = DIGIT_CELLS - 1; i >= 0; i--) {
        if (i != DIGIT_CELLS - 1 && nValue == 0) {
            Slot_SetVisible(hSlots, aCell[i], 0);
        } else {
            Slot_SetVisible(hSlots, aCell[i], 1);
            Slot_ForwardToEntry(hSlots, aCell[i], (u16)(nValue % 10));
        }
        nValue /= 10;
    }
}
