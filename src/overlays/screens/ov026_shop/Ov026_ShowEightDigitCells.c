/* Ov026_ShowEightDigitCells -- Ov008_ShowEightDigitCells: show a number (clamped to
 * 999999) on eight digit cells, most significant first, with a divisor that
 * starts at 10,000,000 and drops by ten per cell.  With bShow clear every cell
 * is hidden.  Leading zeros are hidden until the first non-zero digit (the last
 * cell is always shown); each shown cell gets its digit frame.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define VALUE_MAX   999999
#define CELL_COUNT  8
#define FIRST_DIVISOR 10000000

extern char *data_ov026_02091368;
extern u32  Math_DivMod(u32 nNum, u32 nDen);                          /* Math_DivMod (quotient) */
extern void Slot_SetVisible(int hSlots, int nCell, int bVisible);          /* Slot_SetVisible */
extern void Slot_ForwardToEntry(int hSlots, int nCell, int nFrame);            /* Slot_ForwardToEntry */

void Ov026_ShowEightDigitCells(u32 nValue, int *aCell, int bShow)
{
    int hSlots;
    int i;
    u32 nDigit;
    u32 nDivisor;
    int bLeading;

    hSlots = *(int *)(data_ov026_02091368 + 0xbfb4);
    bLeading = 1;
    nDivisor = FIRST_DIVISOR;
    if (nValue > VALUE_MAX) {
        nValue = VALUE_MAX;
    }
    for (i = 0; i < CELL_COUNT; i++) {
        if (bShow == 0) {
            Slot_SetVisible(hSlots, aCell[i], 0);
        } else {
            nDigit = Math_DivMod(nValue, nDivisor);
            if (bLeading) {
                if (i < CELL_COUNT - 1 && nDigit == 0) {
                    Slot_SetVisible(hSlots, aCell[i], 0);
                } else {
                    bLeading = 0;
                    Slot_SetVisible(hSlots, aCell[i], 1);
                    Slot_ForwardToEntry(hSlots, aCell[i], (u16)nDigit);
                }
            } else {
                Slot_SetVisible(hSlots, aCell[i], 1);
                Slot_ForwardToEntry(hSlots, aCell[i], (u16)nDigit);
            }
            nValue -= nDigit * nDivisor;
            nDivisor /= 10;
        }
    }
}
