/* Resolve the ov022 row for `self` and hand it to the row formatter along with
 * the pair built from the current ov022 selection. The scratch pair lives on the
 * stack and is filled by Ov002_ScreenToCell before the second lookup runs. */
extern int func_ov022_020881f8(void);
extern void Ov002_ScreenToCell(void *out, int value);
extern int func_ov022_02088254(int self);
extern void Ov002_PlotPageGlyph(int self, void *pair, int row);

void Ov002_FormatRowFromSelection(int self) {
    int pair[2];

    Ov002_ScreenToCell(pair, func_ov022_020881f8());
    Ov002_PlotPageGlyph(self, pair, func_ov022_02088254(self));
}
