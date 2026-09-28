/* Update the hovered mission row while dragging. Same gate and same shape as
 * Ov008_RefreshHoveredCell, which does it for the grid: the panel has to be fully idle (+0x68,
 * +0x4f8, +0x30 clear), input enabled and the page not 7. Re-resolves the row and, if it
 * changed from the stored one at +0x54, stores it and refreshes.
 *
 * Ov008_BuildMissionListRows takes TWO arguments, the object and the new row. The park had it as one
 * and read the resulting `mov r1,r0` as the compiler being smarter than the original -- it is
 * the second argument. */
extern int  Ov008_GetCtxObject9634(void);
extern int  Ov008_GetMenuField1408(void);
extern unsigned int Ov008_StepCursorToAcceptedSlot(int obj, int cell);
extern void Ov008_BuildMissionListRows(unsigned int *obj, unsigned int cell);

void Ov008_RefreshHoveredRow(unsigned int *obj) {
    unsigned int row;
    if (obj[0x1a] != 0 || obj[0x13e] != 0 || obj[0xc] != 0) {
        return;
    }
    if (Ov008_GetCtxObject9634() == 0) {
        return;
    }
    if (Ov008_GetMenuField1408() == 7) {
        return;
    }
    row = Ov008_StepCursorToAcceptedSlot((int)obj, 1);
    if (row != *(unsigned char *)((char *)obj + 0x54)) {
        *(unsigned char *)((char *)obj + 0x54) = (unsigned char)row;
        Ov008_BuildMissionListRows(obj, row);
    }
}
